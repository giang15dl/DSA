#include <iostream>
using namespace std;

int tc, T, mana, dis, min_time;
int arr[3][5];// 0 la so phut , 1 la so giay, 2 la nang luong 

int MIN(int a, int b)
{
	if( a < b)
		return a;
	return b;
}

void backtrack(int cur_run ,int cur_time, int cur_dis, int cur_mana)
{
	if( cur_mana < 0)
	{
		return;
	}


	if(cur_mana >=0 && cur_dis == 0)
	{
		min_time = MIN(min_time, cur_time);
		return;
	}

	if(cur_time >= min_time)
	{
		return;
	}

	for(int i = cur_run; i < 5; i++)
	{
		backtrack(i, cur_time + (arr[0][i]*60) + arr[1][i], cur_dis - 1, cur_mana - arr[2][i]); 
	}
}

int main()
{
	cin >>T;
	for(tc = 1; tc <= T; tc++)
	{
		cin >> mana >> dis;
		for(int i = 0;i < 5; i++)
		{
			cin >> arr[0][i] >> arr[1][i] >> arr[2][i] ;
		}
		min_time = 100000;
		backtrack(0,0,dis,mana);
		if(min_time != 100000)
		{
			int phut = 0, giay = 0;
			phut = min_time / 60;
			giay = min_time % 60;
			cout << "Case #" << tc << '\n' << phut << ' ' << giay << '\n';
		}
		else 
			cout << "Case #" << tc << '\n' << -1 << '\n';
	}
	return 0;
}