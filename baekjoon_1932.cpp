#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int arr[600][600];
int dp[600][600];




int main() {
	int i, j;
	int n, k;
	k = 1;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < k; j++)
		{
			scanf("%d", &arr[i][j]);

		}
		k++;
	}

	dp[0][0] = arr[0][0];
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (j == 0) dp[i][j] = dp[i - 1][j] + arr[i][j];
			if (j > 0 && j < k - 1) dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
			if (j == k - 1) dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
		}
		k++;
	}
	int maxi = dp[n - 1][0];
	for (i = 0; i < n; i++)
	{
		maxi = max(dp[n - 1][i], maxi);
	}
	printf("%d", maxi);
	return 0;
}