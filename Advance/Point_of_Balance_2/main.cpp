#include <iostream>

const int T = 10;
const int LIM = 10;
const double EPSILON = 1e-9;

double search(int index, int (&coor)[LIM], int (&mass)[LIM], int N);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        int coor[LIM] = {}; // coordinate, mass
        int mass[LIM] = {}; // coordinate, mass

        for (int i = 0; i < N; i++)
            cin >> coor[i];
        for (int i = 0; i < N; i++)
            cin >> mass[i];

        cout.precision(10);
        cout.setf(ios::fixed, ios::floatfield);
        cout << "#" << t+1 << " ";
        for (int i = 0; i < N - 1; i++) {
            cout << search(i, coor, mass, N) << " ";
        }
        cout << endl;
    }

    return 0;
}

double search(int index, int (&coor)[LIM], int (&mass)[LIM], int N) {
    double left = coor[index];
    double right = coor[index+1];

    double mid, leftF, rightF, diff;

    while (true) {
        mid = (left + right) / 2;
        leftF = rightF = 0;

        for (int i = index; i >= 0; i--)
            leftF += mass[i] / ((mid - coor[i])*(mid - coor[i]));

        for (int i = index + 1; i < N; i++)
            rightF += mass[i] / ((mid - coor[i])*(mid - coor[i]));

        diff = leftF - rightF;

        if (-EPSILON <= diff && diff <= EPSILON)
            return mid;
        else if (diff < 0)
            right = mid;
        else
            left = mid;
    }
}