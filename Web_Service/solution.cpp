#include <string>
#include <vector>
#include <array>

using namespace std;
class Solution {
private:
    static const int MAX_ID = 1000000+1; // IDs ranging from 1 to 1000000
    static const int T = 5; // The maximum number of different hashtags in each test case is 5

    struct Post {
        int id;
        int order;
        int tagNum;
        array<int, T> tags;
        static int n; // Number of posts (whole test case)
        static int m; // Number of tags (whole test case)
        static array<string, T> hashLists;

        static int findHash(char str[]) {
            for (int i = 0; i < m; i++)
                if (hashLists[i] == str)
                    return i;
            hashLists[m++] = str;
            return m - 1;
        }

        Post() : id(0), order(0), tagNum(0) {}

        Post(int id, int tagNum, char tags[5][10]) : id(id), tagNum(tagNum) {
            order = n++;
            for (int i = 0; i < tagNum; i++)
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

    vector<Bucket*> postLists[T][T];

    void insert_posting(int i, int j, Post* new_ps) {
        if (postLists[i][j].back()->front() == 0) {
            buckets[b].clear();
            postLists[i][j].push_back(buckets + b++);
        }
        postLists[i][j].back()->push_front(new_ps);
    }

    void add_posting(Post* _new) {
        for (int y = 0; y < _new->tagNum; y++) {
            insert_posting(_new->tags[y], _new->tags[y], _new);
            for (int x = y + 1; x < _new->tagNum; x++) {
                insert_posting(_new->tags[y], _new->tags[x], _new);
                insert_posting(_new->tags[x], _new->tags[y], _new);
            }
        }
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

public:
    Solution() {}

    Solution(int N, int mPostingIDs[], int mHashTagNum[], char mHashTags[][5][10]) {
        Post::n = 0;
        Post::m = 0;
        b = 0;

        for (int i = 0; i < T; i++)
            for (int j = 0; j < T; j++)
                postLists[i][j].push_back(buckets + b++);

        for (int i = N - 1; i >= 0 ; i--) {
            int ID = mPostingIDs[i];
            posts[ID] = Post(ID, mHashTagNum[i], mHashTags[i]);
            add_posting(posts + ID);
        }
    }

    void addPosting(int mID, int mHashTagNum, char mHashTags[][10]) {
        posts[mID] = Post(mID, mHashTagNum, mHashTags);
        add_posting(posts + mID);
    }

    void removePosting(int mID) {
        for (int y = 0; y < posts[mID].tagNum; y++) {
            remove_posting(posts[mID].tags[y], posts[mID].tags[y], mID);
            for (int x = y + 1; x < posts[mID].tagNum; x++) {
                remove_posting(posts[mID].tags[y], posts[mID].tags[x], mID);
                remove_posting(posts[mID].tags[x], posts[mID].tags[y], mID);
            }
        }
    }

    int findPostingList(int M, char mKeyWords[][10], int mPageNum, int mAnsIDs[]) {
        int y = Post::findHash(mKeyWords[0]);
        int x = y;
        if (M == 2)
            x = Post::findHash(mKeyWords[1]);

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

}*solution;

int Solution::Post::n;
int Solution::Post::m;
array<string, Solution::T> Solution::Post::hashLists;

////////////////////////////////////////////////////////////////////////////////

void init(int N, int mPostingIDs[], int mHashTagNum[], char mHashTags[][5][10]) {
    if(solution)
        delete solution;
    solution = new Solution(N, mPostingIDs, mHashTagNum, mHashTags);
}

void addPosting(int mID, int mHashTagNum, char mHashTags[][10]) {
    solution->addPosting(mID, mHashTagNum, mHashTags);
}

void removePosting(int mID) {
    solution->removePosting(mID);
}


int findPostingList(int M, char mKeyWords[][10], int mPageNum, int mAnsIDs[]) {
    return solution->findPostingList(M, mKeyWords, mPageNum, mAnsIDs);
}
