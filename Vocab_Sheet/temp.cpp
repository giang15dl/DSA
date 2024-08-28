#include <vector>
#include <set>
#include <functional>

#define MAX_N 20000
#define MAX_ID 55000 + 1

using namespace std;

struct Word {
    int row;
    int col;
    int len;
    bool active;

    Word() : active(true) {}
    Word(int row, int col, int len) : row(row), col(col), len(len), active(true) {}

    bool operator()(const Word &curr, const Word &next) const {
        return (curr.col + curr.len - 1) < next.col;
    }

    bool operator<(const Word &that) const {
        return (col + len - 1) < that.col;
    }

}words[MAX_ID];

struct compare {
    bool operator()(int curr, int next) const {
        return (words[curr].col + words[curr].len - 1) < words[next].col;
    }
};

typedef set<Word> TreeSet;

TreeSet treeSet[MAX_N];

class SegmentTree {
public:
    int S;
    int maxColumn;
    vector<int> node;
public:
    SegmentTree() {}

    SegmentTree(int S, int maxColumn) : S(S), maxColumn(maxColumn) {
        node.assign(2 * S, maxColumn);
    }

    // get to leaf
    int query(int val) {
        int ans = -1;

        std::function<void(int, int, int)> binarySearch = [&](int col, int left, int right) -> void {
            if (left == right) {
                ans = left;
                return;
            }
            int mid = (left + right) / 2;
            int leftId = col + 1;
            int rightId = col + 2 * (mid - left + 1);

            if (node[leftId] >= val)
                binarySearch(leftId, left, mid);
            else if (node[rightId] >= val)
                binarySearch(rightId, mid + 1, right);
        };

        binarySearch(1, 0, S - 1);
        return ans;
    }

    // get the leaf and parents
    void update(int row, int val) {
        std::function<void(int, int, int)> binarySearch = [&](int col, int left, int right) -> void {
            if (row < left|| row > right)
                return;

            if (left == right && left == row) {
                node[col] = val;
                return;
            }
            int mid = (left + right) / 2;
            int leftId = col + 1;
            int rightId = col + 2 * (mid - left + 1);

            binarySearch(leftId, left, mid);
            binarySearch(rightId, mid + 1, right);
            node[col] = node[leftId] > node[rightId] ? node[leftId]: node[rightId];
        };
        binarySearch(1, 0, S - 1);
    }

    int getMax(int row) {
        TreeSet::iterator it = treeSet[row].begin();
        Word curr = *it;
        int maxSpace = 0;

        maxSpace = max(maxSpace, curr.col);

        it++;
        while (it != treeSet[row].end()) {
            Word next = *it;
            int emptySpace = next.col - (curr.col + curr.len - 1 ) - 1;
            maxSpace = max(maxSpace, emptySpace);
            curr = next;
            it++;
        }

        int lastSpace = maxColumn - (curr.col + curr.len - 1) - 1;
        maxSpace = max(maxSpace, lastSpace);
        return maxSpace;
    }
}segmentTree;

void init(int N, int M) {
    segmentTree = SegmentTree(N, M);

    for (int i = 0; i < MAX_ID; i++)
        words[i].active = false;

    for (int i = 0; i < MAX_N; i++)
        treeSet[i].clear();
}

int writeWord(int mId, int mLen) {
    if (mLen > segmentTree.node[1])
        return -1;

    int row = segmentTree.query(mLen);
    int col = 0;
    if (!treeSet[row].empty()) {
        TreeSet::iterator it = treeSet[row].begin();
        Word curr = *it;

        if (curr.col >= mLen)
            col = 0;
        else {
            it++;
            while (it != treeSet[row].end()) {
                Word next = *it;
                int emptySpace = next.col - (curr.col + curr.len - 1) - 1;
                if (emptySpace >= mLen)
                    break;

                curr = next;
                it++;
            }
            col = curr.col + curr.len;
        }
    }

    Word newWord(row, col, mLen);
    words[mId] = newWord;
    treeSet[row].insert(newWord);

    int maxSpace = segmentTree.getMax(row);
    segmentTree.update(row, maxSpace);
    return row;
}

int eraseWord(int mId) {
    Word &word = words[mId];
    if (!word.active)
        return -1;

    word.active = false;
    treeSet[word.row].erase(word);

    int maxSpace = !treeSet[word.row].empty() ? segmentTree.getMax(word.row) : segmentTree.S;

    segmentTree.update(word.row, maxSpace);
    return word.row;
}