#include <iostream>
//����:: �̷��͵� dp��!!!!!!! ��ȭ���� �� ������ �������� �ʿ�� ���ٴ� ��. ���� ���� ����ϸ� dp��.
using namespace std;
typedef struct {
	int num;
	int length;
}item;
int ans = 0;
int main() {
	int n;
	cin >> n;
	item arr[1000];
	int i;
	cin >> arr[0].num;
	arr[0].length = 1;
	int flag = 0;
	for (i = 1; i < n; i++)
	{
		int j;
		cin >> arr[i].num;

		arr[i].length = 1;

		for (j = 0; j < i; j++)
		{
			if (arr[i].num > arr[j].num && arr[j].length + 1 > arr[i].length)
			{
				arr[i].length = arr[j].length + 1;
				flag = 1;
			}

			if (arr[i].length > ans) ans = arr[i].length;
		}
	}

	if (!flag) cout << 1;
	else cout << ans;

}