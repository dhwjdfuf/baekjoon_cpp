#include <iostream>	
using namespace std;
int arr[3000][3000];
int minus_one_cnt = 0, zero_cnt = 0, one_cnt = 0;
void fun(int startx, int starty, int n) {//row°¡ xÃà.

	if (n == 1)
	{
		if (arr[startx][starty] == 1) one_cnt++;
		else if (arr[startx][starty] == 0) zero_cnt++;
		else minus_one_cnt++;
		return;
	}

	int i, j;
	int same = 1;
	for (i = startx; i < startx + n; i++)
	{
		int tflag = 0;
		for (j = starty; j < starty + n; j++)
		{
			if (arr[i][j] != arr[startx][starty]) { same = 0; tflag = 1; break; }
		}
		if (tflag) break;
	}

	if (same)
	{
		if (arr[startx][starty] == 1) one_cnt++;
		else if (arr[startx][starty] == 0) zero_cnt++;
		else minus_one_cnt++;

		return;
	}
	else
	{
		fun(startx, starty, n / 3);
		fun(startx + n / 3, starty, n / 3);
		fun(startx + 2 * n / 3, starty, n / 3);

		fun(startx, starty + n / 3, n / 3);
		fun(startx + n / 3, starty + n / 3, n / 3);
		fun(startx + 2 * n / 3, starty + n / 3, n / 3);

		fun(startx, starty + 2 * n / 3, n / 3);
		fun(startx + n / 3, starty + 2 * n / 3, n / 3);
		fun(startx + 2 * n / 3, starty + 2 * n / 3, n / 3);
	}
}
int main() {
	int n;
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	fun(0, 0, n);
	cout << minus_one_cnt << endl;
	cout << zero_cnt << endl;
	cout << one_cnt << endl;
	return 0;
}