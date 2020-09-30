#include <iostream>
#include <algorithm>

using namespace std;
int d[100][100001]; //순서대로 물건, 용량 . i번째 물건까지 사용하여 k용량 까지의 최대가치. 즉 누적 최대 value의 배열이다.
int weight[100];
int value[100];

int big(int a, int b) {
	if (a > b) return a;
	else return b;
}
int main() {
	int n, max;
	cin >> n >> max;
	int i, j;
	for (i = 0; i < n; i++)
	{
		cin >> weight[i] >> value[i];
	}
	int k;

	for (k = 0; k <= max; k++)//k만큼은 인덱스가 실제 용량값이다.
	{
		if (weight[0] > k)
		{
			d[0][k] = 0;
		}
		else
		{
			d[0][k] = value[0];
		}
	}//점화식용 시작값 세팅 완료. 첫 k줄 다 채웠다. 첫 row 다 채웠다.


	for (i = 1; i < n; i++)//여기서, 몇번째 물건 사는지는 고정.
	{
		for (k = 0; k <= max; k++) //i번째 물건을 넣을까 말까를, 용량별로 이제 정해주는거야.
		{
			if (k - weight[i] >= 0)
			{
				d[i][k] = big(d[i - 1][k - weight[i]] + value[i], d[i - 1][k]); //i번재 얘를 넣는다, 안 넣는다의 문제인거야.
			}
			else//k용량 채우는 데에 있어서 weight i가 더 큰 상황. 당연히 넣으면 안되겠지. 그럼 당연히 안넣은상태로 k용량을 채운,
			{
				d[i][k] = d[i - 1][k]; //i가 1 부터 시작이어서, 가능!!
			}

		}
	}

	cout << d[n - 1][max];

}

