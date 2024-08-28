#include <string>
#include <vector>

using namespace std;

const int MAX_ID = 1000000+1; // IDs ranging from 1 to 1000000
const int T = 5; // The maximum number of different hashtags in each test case is 5

int n = 0, m = 0;

string hashList[T];

int findHash(char str[]) {
    for (int i = 0; i < m; i++)
        if (hashList[i] == str)
            return i;

    hashList[m++] = str;
    return m - 1;
}

struct Post {
    int id;
    int order;
    int m;
    int tags[T];

    Post() : id(0), m(0), order(0) {
        for (int i = 0; i < 5; i++)
            this->tags[i] = 0;
    }

    Post(int id, int m, char tags[T][10]) : id(id), m(m) {
        order = n++;
        for (int i = 0; i < m; i++)
            this->tags[i] = findHash(tags[i]);
    }
}posts[MAX_ID];

class Bucket {
private:
    static const int SIZE = 1000;
    Post* arr[SIZE];
    int f, r;

public:
    Bucket() : r(SIZE - 1), f(SIZE - 1){}

    int front() const {
        return f;
    }

    void push_front(Post* a) {
        arr[--f] = a;
    }

    void clear() {
        f = r = SIZE - 1;
    }

    bool empty() {
        return f == r;
    }

    Post* begin() {
        return arr[f];
    }

    Post* end() {
        return arr[r - 1];
    }

    void erase(int id) {
        for (int i = f; i < r; i++) {
            if (arr[i]->id == id) {
                for (int j = i + 1; j < r; j++)
                    arr[j - 1] = arr[j];

                r--;
                break;
            }
        }
    }

    int size() {
        return r - f;
    }

    int get(int index) {
        return arr[f + index]->id;
    }
}buckets[3000];

int b;

vector<Bucket*> postLists[5][5];

void insert_posting(int y, int x, Post* new_ps) {
    if (postLists[y][x].back()->front() == 0) {
        buckets[b].clear();
        postLists[y][x].push_back(buckets + b);
        b += 1;
    }
    postLists[y][x].back()->push_front(new_ps);
}

void add_posting(Post* _new) {
    for (int y = 0; y < _new->m; y++) {
        insert_posting(_new->tags[y], _new->tags[y], _new);
        for (int x = y + 1; x < _new->m; x++) {
            insert_posting(_new->tags[y], _new->tags[x], _new);
            insert_posting(_new->tags[x], _new->tags[y], _new);
        }
    }
}

void init(int N, int mPostingIDs[], int mHashTagNum[], char mHashTags[][5][10]) {
    n = m = b = 0;

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            postLists[i][j].clear();
            buckets[b].clear();
            postLists[i][j].push_back(buckets + b);
            b++;
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        int ID = mPostingIDs[i];
        posts[ID] = Post(ID, mHashTagNum[i], mHashTags[i]);
        add_posting(posts + ID);
    }
}


void addPosting(int mID, int mHashTagNum, char mHashTags[][10]) {
    posts[mID] = Post(mID, mHashTagNum, mHashTags);
    add_posting(posts + mID);
}

void remove_posting(int y, int x, int ID) {
    for (unsigned int i = 0; i < postLists[y][x].size(); i++) {
        if (postLists[y][x][i]->empty() == true)
            continue;

        int hi = postLists[y][x][i]->begin()->order;
        int lo = postLists[y][x][i]->end()->order;

        if (posts[ID].order > hi || posts[ID].order < lo)
            continue;

        postLists[y][x][i]->erase(ID);
    }
}

void removePosting(int mID) {
    for (int y = 0; y < posts[mID].m; y++) {
        remove_posting(posts[mID].tags[y], posts[mID].tags[y], mID);
        for (int x = y + 1; x < posts[mID].m; x++) {
            remove_posting(posts[mID].tags[y], posts[mID].tags[x], mID);
            remove_posting(posts[mID].tags[x], posts[mID].tags[y], mID);
        }
    }
}

int findPostingList(int M, char mKeyWords[][10], int mPageNum, int mAnsIDs[]) {
    int y = findHash(mKeyWords[0]);
    int x = y;
    if (M == 2)
        x = findHash(mKeyWords[1]);

    int from = (mPageNum - 1) * 10;
    int ret = 0;

    for (int i = postLists[y][x].size() - 1; i >= 0 && ret < 10; i--) {
        int sz = postLists[y][x][i]->size();
        if (from >= sz) {
            from -= sz;
            continue;
        }

        for (int j = from; j < sz && ret < 10; j++)
            mAnsIDs[ret++] = postLists[y][x][i]->get(j);

        if (ret == 10)
            break;

        from = 0;
    }
    return ret;
}
