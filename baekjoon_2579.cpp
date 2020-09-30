#include <iostream>
using namespace std;
typedef struct {
	int bc_flag; //bc를 보는 flag. 
	int score;
	unsigned long long ac_score;
	unsigned long long bc_score;
}stair;
//각 step에 저장하는것, 직전이 ac일때의 최대점수와, bc 일 때의 최대점수야.
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() { //whats the difference between brute force...!!!!! 난 이문제 딱 보자마자 당연히 brute force 해야 하는 거 아닌가 ㅠㅠ 이러고 있었는데..!
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

		arr[i].ac_score = max(arr[i - 2].ac_score, arr[i - 2].bc_score) + arr[i].score; //여기는 어차피 점프기 때문에, 아무렇게나 해도돼.
		//ac는 끝~

		if (arr[i - 1].ac_score > arr[i - 1].bc_score) //전에서 ac가 더 클때는, 무리없이 bc를 사용할 수 있지.
		{
			arr[i].bc_score = arr[i - 1].ac_score + arr[i].score;
		}
		else //여기가 문제야. 전에도 bc가 더 컸어. 이때 bc를 쓸때는 전의 ac로 가야돼.
		{
			arr[i].bc_score = arr[i - 1].ac_score + arr[i].score;
		}

	}
	cout << max(arr[n - 1].ac_score, arr[n - 1].bc_score);
}