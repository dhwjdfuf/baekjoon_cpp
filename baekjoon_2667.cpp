#include <stdio.h>
#include <string.h>
#include <stdlib.h>

short int map[25 * 25];
short int matrix[25 * 25][25 * 25]; //이 넘버링된 vertex간의 그래프 매트릭스.
short int visited[25 * 25] = { 0, }; //모든 vertex에 넘버링을 했다.
int counts[625] = { 0, };
int count = 0;
int kk = 0;
int n;

void dfs(int v) {
	visited[v] = 1;
	count++;
	int i;
	for (i = 0; i < n*n; i++)
	{
		if (matrix[v][i])
		{
			if (!visited[i])
			{
				dfs(i);
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n*n; i++)
	{
		scanf("%1d", &map[i]);
	}
	for (i = 0; i < n*n - n; i++)//세로 연결
	{
		if (map[i] && map[i + n])
		{
			matrix[i][i + n] = matrix[i + n][i] = 1;
		}
	}
	for (i = 0; i < n*n - 1; i++)//가로연결
	{
		if (i%n == n - 1) continue;

		if (map[i] && map[i + 1])
		{
			matrix[i][i + 1] = matrix[i + 1][i] = 1;
		}
	}

	//이렇게, matrix 작성 완료.


	for (i = 0; i < n*n; i++)
	{
		if (!visited[i] && map[i])
		{
			dfs(i); //연결된 모든 거에 visited 찍는 행위.
			counts[kk++] = count;
			count = 0;
		}
	}

	printf("%d\n", kk);
	for (i = 0; i < kk; i++)
	{
		for (j = i; j < kk; j++)
		{
			if (counts[j] < counts[i])
			{
				int temp;
				temp = counts[j];
				counts[j] = counts[i];
				counts[i] = temp;
			}
		}
	}

	for (i = 0; i < kk; i++)
	{
		printf("%d\n", counts[i]);
	}

	return 0;
}