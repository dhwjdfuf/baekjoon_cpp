#include <iostream>
using namespace std;
typedef struct {
	int bc_flag; //bc�� ���� flag. 
	int score;
	unsigned long long ac_score;
	unsigned long long bc_score;
}stair;
//�� step�� �����ϴ°�, ������ ac�϶��� �ִ�������, bc �� ���� �ִ�������.
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() { //whats the difference between brute force...!!!!! �� �̹��� �� ���ڸ��� �翬�� brute force �ؾ� �ϴ� �� �ƴѰ� �Ф� �̷��� �־��µ�..!
	stair arr[300] = { 0, };
	int n;
	cin >> n;
	if (n == 1)
	{
		int first;
		cin >> first;
		cout << first;
		return 0;
	}
	else if (n == 2)
	{
		int first, second;
		cin >> first >> second;
		cout << first + second;
		return 0;
	}
	cin >> arr[0].score >> arr[1].score >> arr[2].score;

	arr[0].ac_score = arr[0].score;
	arr[0].bc_score = arr[0].score;
	arr[0].bc_flag = 0;

	arr[1].ac_score = arr[1].score;
	arr[1].bc_score = arr[0].score + arr[1].score;
	arr[1].bc_flag = 1;

	arr[2].ac_score = arr[0].score + arr[2].score;
	arr[2].bc_score = arr[1].score + arr[2].score;
	arr[2].bc_flag = 1;

	int i;
	for (i = 3; i < n; i++)
	{
		cin >> arr[i].score;

		arr[i].ac_score = max(arr[i - 2].ac_score, arr[i - 2].bc_score) + arr[i].score; //����� ������ ������ ������, �ƹ����Գ� �ص���.
		//ac�� ��~

		if (arr[i - 1].ac_score > arr[i - 1].bc_score) //������ ac�� �� Ŭ����, �������� bc�� ����� �� ����.
		{
			arr[i].bc_score = arr[i - 1].ac_score + arr[i].score;
		}
		else //���Ⱑ ������. ������ bc�� �� �Ǿ�. �̶� bc�� ������ ���� ac�� ���ߵ�.
		{
			arr[i].bc_score = arr[i - 1].ac_score + arr[i].score;
		}

	}
	cout << max(arr[n - 1].ac_score, arr[n - 1].bc_score);
}