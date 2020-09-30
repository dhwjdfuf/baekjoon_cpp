#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[100000];
	int n;
	cin >> n;
	int i;
	cin >> arr[0];
	for (i = 1; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (arr[i - 1] < 0)
		{
			arr[i] = temp;
		}
		else
		{
			arr[i] = arr[i - 1] + temp;
		}
	}

	cout << *max_element(arr, arr + n);
}