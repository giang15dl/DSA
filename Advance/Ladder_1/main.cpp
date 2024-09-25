#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

// direction to go from bottom: right, left, up.
const int dx[3] = {1,-1,0};
const int dy[3] = {0,0,-1};

int main(int argc, char** argv)
{	
    freopen("ladder1_test_input.txt", "r", stdin);

	for(int tc = 0; tc < 10; tc++)
	{
        int tc_index = 0;
        cin >> tc_index;

        int matrix[100][100] = {};
        int flag[100][100] = {};

        int end_point = 0;

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                cin >> matrix[i][j];
                if (i==99 && matrix[i][j] == 2)
                {
                    end_point = j;
                }
            }
        }
        int y=99;
        int x=end_point;

        while (y>0)
        {
            for (int i = 0; i < 3; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx>=0 && nx<100 && matrix[ny][nx]==1 && flag[ny][nx]==0)
                {
                    flag[ny][nx] = 1;
                    x = nx;
                    y = ny;
                    break;
                }
            }
        }

        cout << "#" << tc_index << " " << x << endl;
	}

	return 0;
}
