#include <iostream>

class SegmentTree {
private:
    int* STree;
    int size;
    int level;

public:
    void init(int arrSize) {
        level = 0;
        while (power(2, level) < arrSize)
            level++;
        size = power(2, level);
        STree = new int[size * 2 - 1];
        for (int i = 0; i < size * 2 - 1; i++) {
            STree[i] = 0;
        }
    }
    int power(int a, int n) {
        if (n == 1)
            return a;
        if (n == 0)
            return 1;
        int p = power(a, n / 2);
        if (n % 2 == 1)
            return p * p * a;
        return p * p;
    }
    void updateInternal(int index, int left, int right, int i, int value) {
        if (i < left || i > right)
            return;
        if (left == right) {
            STree[index] = value;
            return;
        }
        int mid = (left + right) / 2;
        updateInternal(index * 2 + 1, left, mid, i, value);
        updateInternal(index * 2 + 2, mid + 1, right, i, value);
        STree[index] = max(STree[index * 2 + 1], STree[index * 2 + 2]);
    }
    void update(int i, int value) {
        updateInternal(0, 0, size - 1, i, value);
    }
    int getMaxOfSectionInternal(int index, int left, int right, int start, int end) {
        if (start > right || end < left)
            return 0;
        if ((start <= left && end >= right)) {
            return STree[index];
        }
        int mid = (left + right) / 2;
        return max(getMaxOfSectionInternal(index * 2 + 1, left, mid, start, end),
            getMaxOfSectionInternal(index * 2 + 2, mid + 1, right, start, end));
    }
    int getMaxOfSection(int start, int end) {
        return getMaxOfSectionInternal(0, 0, size - 1, start, end);
    }

    int getSize() {
        return size;
    }
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
};

using namespace std;
int main() {
    int arr[10] = {1,2,9,4,5,6,7,8,9,10};
    SegmentTree st;
    st.init(10);
    for (int i = 0; i < 10; i++) {
        st.update(i, arr[i]);
    }

    int max = st.getMaxOfSection(1, 5);

    return 0;
}
