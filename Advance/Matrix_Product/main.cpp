#define _CRT_SECURE_NO_WARNINGS // Suppress Warning	C4996: 'freopen': This function or variable may be unsafe. Consider using freopen_s instead.
#include <iostream>
using namespace std;

const int DIV = 100000007;  // should be 100000007
const int MAX_N = 100;      // should be 100
const int MAX_M = 10000000; // should be 10000000

template <typename T = unsigned long long, unsigned int MAX = MAX_N>
class Matrix {
private:
    int size;
    T data[MAX][MAX];

public:
    Matrix(int size);

    T &operator()(int i, int j);
    T operator()(int i, int j) const;
    Matrix operator*(const Matrix &mat) const;
    void operator*=(const Matrix &mat);
    Matrix operator^(int exp) const; // Power operator, not XOR operator.
    Matrix operator%(const int &div) const;
    bool operator==(const int &rhs) const;
    friend ostream &operator<<(ostream &os, const Matrix<> &mat);
    friend istream &operator>>(istream &is, Matrix<> &mat);

    Matrix QuickModular(int exp, const int &div) const;
    int Size() const;
};

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int N, M;
        cin >> N >> M;

        Matrix<> mat(N);
        cin >> mat;

        cout << "Case #" << tc + 1 << endl;
        cout << mat.QuickModular(M, DIV);
    }

    return 0;
}

template <typename T, unsigned int MAX>
Matrix<T, MAX>::Matrix(int size) {
    this->size = size;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            data[i][j] = 0;
}

template <typename T, unsigned int MAX>
T &Matrix<T, MAX>::operator()(int i, int j) {
    return data[i][j];
}

template <typename T, unsigned int MAX>
T Matrix<T, MAX>::operator()(int i, int j) const {
    return data[i][j];
}

template <typename T, unsigned int MAX>
int Matrix<T, MAX>::Size() const {
    return this->size;
}

template <typename T, unsigned int MAX>
Matrix<T, MAX> Matrix<T, MAX>::operator*(const Matrix &mat) const {
    Matrix mat_res(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for (int k = 0; k < size; k++)
                mat_res(i, j) += (*this)(i, k) * mat(k, j);

    return mat_res;
}

template <typename T, unsigned int MAX>
void Matrix<T, MAX>::operator*=(const Matrix &mat) {
    (*this) = (*this) * mat;
}

template <typename T, unsigned int MAX>
Matrix<T, MAX> Matrix<T, MAX>::operator^(int exp) const {
    int size = this->Size();
    Matrix res(size);

    // Initialize res as an Identity matrix.
    for (int i = 0; i < size; i++)
        res(i, i) = 1;

    Matrix x = (*this);

    while (exp > 0) {
        if (exp % 2 == 1)
            res *= x;

        exp /= 2;
        x *= x;
    }

    return res;
}

template <typename T, unsigned int MAX>
Matrix<T, MAX> Matrix<T, MAX>::QuickModular(int exp, const int &div) const {
    int size = this->Size();
    Matrix rem(size);

    // Initialize res as an Identity matrix.
    for (int i = 0; i < size; i++)
        rem(i, i) = 1;

    Matrix x = (*this);

    x = x % div;

    if (x == 0)
        return x;

    while (exp > 0) {
        if (exp % 2 == 1) {
            rem *= x;
            rem = rem % div;
        }

        exp /= 2;
        x *= x;
        x = x % div;
    }

    return rem;
}

template <typename T, unsigned int MAX>
Matrix<T, MAX> Matrix<T, MAX>::operator%(const int &div) const {
    Matrix rem = *this;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            rem(i, j) %= div;

    return rem;
}

template <typename T, unsigned int MAX>
bool Matrix<T, MAX>::operator==(const int &rhs) const {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (this->data[i][j] != rhs)
                return false;

    return true;
}

ostream &operator<<(ostream &os, const Matrix<> &mat) {
    for (int i = 0; i < mat.Size(); i++) {
        for (int j = 0; j < mat.Size(); j++)
            cout << mat(i, j) << " ";
        cout << endl;
    }

    return os;
}

istream &operator>>(istream &is, Matrix<> &mat) {
    for (int i = 0; i < mat.Size(); i++)
        for (int j = 0; j < mat.Size(); j++)
            is >> mat(i, j);

    return is;
}
