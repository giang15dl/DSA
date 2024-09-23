#include <string>

const int MAX_H = 300;

using namespace std;
class Solution {
private:
    template <class T, const int SIZE = 302>
    class circular_queue {
    private:
        T data[SIZE];
        int front, rear;
        int count[26];

        int next(int x) const {
            return x != SIZE - 1 ? x + 1 : 0;
        }

        int prev(int x) const {
            return x != 0 ? x - 1 : SIZE - 1;
        }

    public:
        circular_queue() : front(0), rear(0) {
            for (int i = 0; i < 26; i++)
                count[i] = 0;
        }

        int size() const {
            int length = front - rear;
            if (length < 0)
                length += SIZE;
            return length;
        }

        char back() const {
            return data[prev(front)];
        }

        void push_front(T ch) {
            count[ch - 'a']++;
            rear = prev(rear);
            data[rear] = ch;
        }

        void push_back(T ch) {
            count[ch - 'a']++;
            data[front] = ch;
            front = next(front);
        }

        void pop_back() {
            front = prev(front);
            count[data[front] - 'a']--;
        }

        T &operator[](int p) {
            int idx = rear + p;
            if (idx >= SIZE)
                idx -= SIZE;
            return data[idx];
        }

        void insert(int pos, T ch) {
            ++count[ch - 'a'];
            int idx = rear + pos;
            if (idx >= SIZE)
                idx -= SIZE;
            for (int i = front; i != idx;) {
                int j = prev(i);
                data[i] = data[j];
                i = j;
            }
            data[idx] = ch;
            front = next(front);
        }

        int countChar(T ch) {
            return count[ch - 'a'];
        }
    };

    circular_queue<char> lines[MAX_H];
    int cursor;
    int H, W;
    int length;

public:
    Solution(int H = 0, int W = 0, char mStr[] = "") : H(H), W(W), length(0), cursor(0) {
        while (mStr[length]) {
            lines[length / W].push_back(mStr[length]);
            ++length;
        }
    }

    // 300 * 300 * 30000 = 2700000000 = 27 * 10^8
    void insert(char mChar) {
        int r = cursor / W, c = cursor % W;
        lines[r].insert(c, mChar);

        int p = r;

        while (lines[p].size() > W) {
            char ch = lines[p].back();
            lines[p + 1].push_front(ch);
            lines[p++].pop_back();
        }
        cursor++, length++;
    }

    // 30000 = 3 * 10^4
    char moveCursor(int mRow, int mCol) {
        cursor = mRow * W + mCol;
        if (cursor >= length) {
            cursor = length;
            return '$';
        }
        return lines[cursor / W][cursor % W];
    }

    // 300 * 40000 = 12 * 10^6
    int countCharacter(char mChar) {
        int r = cursor / W, c = cursor % W;
        int matches = 0;
        for (int i = c; i < lines[r].size(); i++)
            if (lines[r][i] == mChar)
                ++matches;

        for (int i = r + 1; i < H; i++)
            matches += lines[i].countChar(mChar);

        return matches;
    }
} solution;

///////////////////////////////////////////////////////////////////////////////
void init(int H, int W, char mStr[]) { solution = Solution(H, W, mStr); }
void insert(char mChar) { solution.insert(mChar); }
char moveCursor(int mRow, int mCol) { return solution.moveCursor(mRow - 1, mCol - 1); }
int countCharacter(char mChar) { return solution.countCharacter(mChar); }