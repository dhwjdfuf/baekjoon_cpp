#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int*arr;
	arr = new int[n + 3];
	//int arr[1000001];
	arr[1] = 1;
	arr[2] = 2;
	int i;
	for (i = 3; i < n + 1; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	}

	cout << arr[n];
	return 0;
}