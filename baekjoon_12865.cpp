#include <iostream>
#include <algorithm>

using namespace std;
int d[100][100001]; //������� ����, �뷮 . i��° ���Ǳ��� ����Ͽ� k�뷮 ������ �ִ밡ġ. �� ���� �ִ� value�� �迭�̴�.
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

	for (k = 0; k <= max; k++)//k��ŭ�� �ε����� ���� �뷮���̴�.
	{
		if (weight[0] > k)
		{
			d[0][k] = 0;
		}
		else
		{
			d[0][k] = value[0];
		}
	}//��ȭ�Ŀ� ���۰� ���� �Ϸ�. ù k�� �� ä����. ù row �� ä����.


	for (i = 1; i < n; i++)//���⼭, ���° ���� ������� ����.
	{
		for (k = 0; k <= max; k++) //i��° ������ ������ ���, �뷮���� ���� �����ִ°ž�.
		{
			if (k - weight[i] >= 0)
			{
				d[i][k] = big(d[i - 1][k - weight[i]] + value[i], d[i - 1][k]); //i���� �긦 �ִ´�, �� �ִ´��� �����ΰž�.
			}
			else//k�뷮 ä��� ���� �־ weight i�� �� ū ��Ȳ. �翬�� ������ �ȵǰ���. �׷� �翬�� �ȳ������·� k�뷮�� ä��,
			{
				d[i][k] = d[i - 1][k]; //i�� 1 ���� �����̾, ����!!
			}

		}
	}

	cout << d[n - 1][max];

}

