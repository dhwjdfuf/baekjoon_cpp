#include <stdio.h>
#define N 105
#define mod 1000000000
int main() {
	int n;
	long dp[N][10];
	scanf("%d", &n);
	int i, j;
	for (j = 0; j < 10; j++)
	{
		dp[1][j] = 1;
	}
	dp[1][0] = 0;
	for (i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1] % mod;
		for (j = 1; j < 10; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;

		}
		dp[i][9] = dp[i - 1][8] % mod;
	}
	long sum = 0;
	for (i = 0; i < 10; i++)
	{
		sum += dp[n][i];
	}
	printf("%d", sum%mod);
	return 0;
}