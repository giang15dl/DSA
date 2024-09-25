struct Point {
    int i, j;

    Point() : i(0), j(0) {}

    Point(int i, int j) : i(i), j(j) {}

    bool operator>(const int &rhs) const {
        return i > rhs && j > rhs;
    }

    bool operator>=(const int &rhs) const {
        return i >= rhs && j >= rhs;
    }

    bool operator<(const int &rhs) const {
        return i < rhs && j < rhs;
    }

    bool operator<=(const int &rhs) const {
        return i <= rhs && j <= rhs;
    }

    bool operator<(const Point &rhs) const {
        return i < rhs.i && j < rhs.j;
    }

    bool operator<=(const Point &rhs) const {
        return i <= rhs.i && j <= rhs.j;
    }

    bool operator>(const Point &rhs) const {
        return i > rhs.i && j > rhs.j;
    }

    bool operator>=(const Point &rhs) const {
        return i >= rhs.i && j >= rhs.j;
    }

    bool operator==(const Point &rhs) const {
        return i == rhs.i && j == rhs.j;
    }

    bool operator!=(const Point &rhs) const {
        return i != rhs.i || j != rhs.j;
    }

    Point operator+(const Point &rhs) const {
        return Point(i + rhs.i, j + rhs.j);
    }

    Point operator-(const Point &rhs) const {
        return Point(i - rhs.i, j - rhs.j);
    }

    void operator+=(const Point &rhs) {
        i += rhs.i;
        j += rhs.j;
    }

    void operator-=(const Point &rhs) {
        i -= rhs.i;
        j -= rhs.j;
    }

    void operator+=(const int &rhs) {
        i += rhs;
        j += rhs;
    }

    void operator-=(const int &rhs) {
        i -= rhs;
        j -= rhs;
    }

    Point &operator++() { // Prefix
        ++i;
        ++j;
        return *this;
    }

    Point &operator--() { // Prefix
        --i;
        --j;
        return *this;
    }

    Point operator++(int) { // Postfix
        Point temp = *this;
        ++(*this);
        return temp;
    }

    Point operator--(int) { // Postfix
        Point temp = *this;
        --(*this);
        return temp;
    }

    bool valid(const int &R, const int &C) const {
        return i >= 0 && j >= 0 && i < R && j < C;
    }

    bool valid(const int &N) const {
        return i >= 0 && j >= 0 && i < N && j < N;
    }

    bool valid(const Point &Size) const {
        return i >= 0 && j >= 0 && i < Size.i && j < Size.j;
    }
};
