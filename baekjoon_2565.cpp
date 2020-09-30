#include <iostream>
using namespace std;
typedef struct {
	int A;
	int B;
	int length;
}item;
item arr[100];

void sort(int n) {
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (arr[i].A < arr[j].A)
			{
				int tempa, tempb, templength;
				tempa = arr[i].A;
				tempb = arr[i].B;
				templength = arr[i].length;

				arr[i].A = arr[j].A;
				arr[i].B = arr[j].B;
				arr[i].length = arr[j].length;

				arr[j].A = tempa;
				arr[j].B = tempb;
				arr[j].length = templength;

			}
		}
	}
}
int main() {
	int n;
	cin >> n;

	int i;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i].A >> arr[i].B;
	}

	if (n == 1) { cout << 0; return 0; }

	sort(n);
	int ans = 0;
	arr[0].length = 1;
	int flag = 0;
	for (i = 1; i < n; i++)
	{
		int j;
		arr[i].length = 1;

		for (j = 0; j < i; j++)
		{
			if (arr[i].B > arr[j].B && arr[j].length + 1 > arr[i].length)
			{
				arr[i].length = arr[j].length + 1;
				flag = 1;
			}

			if (arr[i].length > ans) ans = arr[i].length;
		}
	}

	cout << n - ans;
}
