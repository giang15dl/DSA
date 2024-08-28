#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "list.hpp"

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cout << "#" << t + 1 << " " ;
        int N;
        cin >> N;

        list<int> dl;
        for (int i = 0; i < N; i++) {
            char cmd;
            int j, K;

            cin >> cmd;
            switch (cmd) {
            case 'f': // insert front
                cin >> K;
                dl.push_front(K);
                break;

            case 'i': // insert
                cin >> j >> K;
                j++;
                dl.insert(j, K);
                break;

            case 'r': // replace
                dl.pop_front();
                break;

            case 'd': // delete
                cin >> j;
                j++;
                dl.erase(j);
                break;
            case 'p': // print
                cin >> j;
                dl.print(j);
                break;

            default:
                break;
            }
        }
        cout << endl;
    }

    return 0;
}