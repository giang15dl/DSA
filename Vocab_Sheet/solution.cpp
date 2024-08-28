#include <vector>
#include <set>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
    static const int MAX_N = 20000;
    static const int MAX_M = 1000;
    static const int MAX_ID = 50000 + 1;
private:
    int N, M;

    struct Word {
        int row;
        int col;
        int len;
        bool active;

        Word() : active(false) {}
        Word(int row, int col, int len) : row(row), col(col), len(len), active(true) {}

        bool operator()(const Word &curr, const Word &next) const {
            return (curr.col + curr.len - 1) < next.col;
        }

        bool operator<(const Word &that) const {
            return (col + len - 1) < that.col;
        }

    }words[MAX_ID];

    set<Word> treeSet[MAX_N];

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

        int getMax(int row, set<Word> *treeSet) {
            set<Word>::iterator it = treeSet[row].begin();
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

public:
    // N: number of rows (5 <= N <= 20,000)
    // M: number of columns (5 <= M <= 1000)
    Solution(int N = 0, int M = 0) : N(0), M(0) {
        segmentTree = SegmentTree(N, M);
    }

    // Write a word on the paper
    // mId: ID of the word (1 <= mId <= 50,000)
    // mLen: length of the word (2 <= mLen <= M)
    // return: row number of the location where the word is written.
    // If cannot write the word on the paper, returned -1.
    // - All cells to be written must be empty.
    // - All letters of the word must be written in a single row.
    // - If there is multiple available locations, choose the one with smallest row and smallest collumn.
    // - The ID value starts from 1 and increases by 1 every time this function is called.
    // - It is guaranteed that the maximum number of words written in a single row on the paper is 60.
    // Called up to 50000 times
    // 50000 * (1000 + sqrt(20000)) ~ 5.7*10^7
    int writeWord(int mId, int mLen) {
        if (mLen > segmentTree.node[1])
            return -1;

        int row = segmentTree.query(mLen);
        int col = 0;
        if (!treeSet[row].empty()) {
            set<Word>::iterator it = treeSet[row].begin();
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

        int maxSpace = segmentTree.getMax(row, treeSet);
        segmentTree.update(row, maxSpace);
        return row;
    }

    // Remove the word which ID is mId. After removal, the cells that were occupied become empty.
    // mId: ID of the word to be removed (1 <= id <= 55000)
    // return: row number of the location where the word is removed.
    // If the word cannot be removed (invalid id or already removed word), return -1.
    // Called up to 5000 times
    // 5000 * log(60) *  log(60) * log(60) ~ 3*10^5
    //        erase()    getMax()  update()
    int eraseWord(int mId) {
        Word &word = words[mId];
        if (!word.active)
            return -1;

        word.active = false;
        treeSet[word.row].erase(word);

        int maxSpace = !treeSet[word.row].empty() ? segmentTree.getMax(word.row, treeSet) : segmentTree.S;

        segmentTree.update(word.row, maxSpace);
        return word.row;
    }
} *solution;

///////////////////////////////////////////////////////////////////////////////
void init(int N, int M) { solution = new Solution(N, M); }
int writeWord(int mId, int mLen) { return solution->writeWord(mId, mLen); }
int eraseWord(int mId) { return solution->eraseWord(mId); }