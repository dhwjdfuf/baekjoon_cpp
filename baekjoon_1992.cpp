#include <iostream>	
#include <stdio.h>
#include <list>
using namespace std;
int arr[64][64];
int bcnt = 0, wcnt = 0;
list<char> ans;

void fun(int startx, int starty, int n, list<char>::iterator itr) {//row가 x축.

	if (n == 1)
	{
		if (arr[startx][starty])
		{
			ans.insert(itr, '1');
		}
		else ans.insert(itr, '0');


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
		if (arr[startx][starty])
		{
			ans.insert(itr, '1');
		}
		else ans.insert(itr, '0');


	}
	else
	{
		ans.insert(itr, '(');
		ans.insert(itr, ')');
		itr--;

		fun(startx, starty, n / 2, itr);
		fun(startx, starty + n / 2, n / 2, itr);
		fun(startx + n / 2, starty, n / 2, itr);
		fun(startx + n / 2, starty + n / 2, n / 2, itr);
	}
}
int main() {
	int n;
	int i, j;
	list<char>::iterator itr;

	itr = ans.begin();	//이렇게 headerpointer 지정 가능~

	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	fun(0, 0, n, itr);
	list<char>::iterator loc;
	for (loc = ans.begin(); loc != ans.end(); loc++)
	{
		cout << *loc;
	}
	return 0;
}