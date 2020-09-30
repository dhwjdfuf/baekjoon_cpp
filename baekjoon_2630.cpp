#include <iostream>	
using namespace std;
int arr[128][128];
int bcnt = 0, wcnt = 0;
void fun(int startx, int starty, int n) {//row°¡ xÃà.

	if (n == 1)
	{
		if (arr[startx][starty]) bcnt++;
		else wcnt++;
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
		if (arr[startx][starty]) bcnt++;
		else wcnt++;
		return;
	}
	else
	{
		fun(startx, starty, n / 2);
		fun(startx + n / 2, starty, n / 2);
		fun(startx, starty + n / 2, n / 2);
		fun(startx + n / 2, starty + n / 2, n / 2);
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
	cout << wcnt << endl;
	cout << bcnt << endl;
	return 0;
}