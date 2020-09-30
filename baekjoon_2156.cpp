#include <stdio.h>	
#define N 10001
#define max(a,b)	((a)>(b)?(a):(b))
int arr[N];
int count;
int dp[N];
int main() {
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	dp[0] = arr[0]; count = 1;
	dp[1] = arr[0] + arr[1]; count = 2;
	for (i = 2; i < n; i++)
	{
		int first = dp[i - 3] + arr[i] + arr[i - 1];//두개 연속.
		int second = arr[i] + dp[i - 2];// 건너뛰고 하나.
		int third = dp[i - 1];
		dp[i] = max(first, max(second, third));

	}
	printf("%d", dp[n - 1]);
	return 0;
}