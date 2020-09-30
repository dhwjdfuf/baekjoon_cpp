#include <iostream>
#include <stdio.h>
using namespace std;
#include <queue>
#define max 210000000

typedef struct {
	int x, y;
}node;
bool map[1000][1000];
int dist[1000][1000];
int main() {
	int n, m;
	cin >> n >> m;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
			dist[i][j] = max;
		}
	}


	dist[0][0] = 1;					//(x,y)까지 부수지 않고 갈수 있는 최단거리.

	queue <node> q;
	node head;
	queue <node> newq;

	head.x = 0; head.y = 0;
	q.push(head);

	for (; !q.empty();)
	{
		node cur = q.front();
		q.pop();

		node left, right, up, down;
		left.x = cur.x; left.y = cur.y - 1;
		right.x = cur.x; right.y = cur.y + 1;
		up.x = cur.x - 1; up.y = cur.y;
		down.x = cur.x + 1; down.y = cur.y;
		if (cur.x < n - 1 && dist[cur.x][cur.y] + 1 < dist[cur.x + 1][cur.y]) //down
		{

			if (map[cur.x + 1][cur.y]) //벽으로 차있어. 당연히 break 하는 것만 큐에 넣으면 된다.
			{
				newq.push(down);
			}
			else //뚫려있으므로, unbreak하는 것만 넣으면 된다.
			{
				q.push(down);
			}
			dist[cur.x + 1][cur.y] = dist[cur.x][cur.y] + 1;

		}

		if (cur.y < m - 1 && dist[cur.x][cur.y] + 1 < dist[cur.x][cur.y + 1]) //right
		{
			if (map[cur.x][cur.y + 1])
			{
				newq.push(right);
			}
			else
			{
				q.push(right);
			}
			dist[cur.x][cur.y + 1] = dist[cur.x][cur.y] + 1;


		}
		if (cur.x > 0 && dist[cur.x][cur.y] + 1 < dist[cur.x - 1][cur.y]) //up
		{
			if (map[cur.x - 1][cur.y])
			{
				newq.push(up);
			}
			else
			{
				q.push(up);
			}
			dist[cur.x - 1][cur.y] = dist[cur.x][cur.y] + 1;

		}
		if (cur.y > 0 && dist[cur.x][cur.y] + 1 < dist[cur.x][cur.y - 1]) //left
		{
			if (map[cur.x][cur.y - 1])
			{
				newq.push(left);
			}
			else
			{
				q.push(left);
			}
			dist[cur.x][cur.y - 1] = dist[cur.x][cur.y] + 1;

		}
	}


	for (; !newq.empty();)
	{
		node cur = newq.front();
		newq.pop();

		node left, right, up, down;
		left.x = cur.x; left.y = cur.y - 1;
		right.x = cur.x; right.y = cur.y + 1;
		up.x = cur.x - 1; up.y = cur.y;
		down.x = cur.x + 1; down.y = cur.y;

		{
			if (cur.x < n - 1 && dist[cur.x][cur.y] + 1 < dist[cur.x + 1][cur.y]) //down
			{

				if (!map[cur.x + 1][cur.y])
				{
					newq.push(down);
					dist[cur.x + 1][cur.y] = dist[cur.x][cur.y] + 1;
				}

			}

			if (cur.y < m - 1 && dist[cur.x][cur.y] + 1 < dist[cur.x][cur.y + 1]) //right
			{
				if (!map[cur.x][cur.y + 1])
				{
					newq.push(right);
					dist[cur.x][cur.y + 1] = dist[cur.x][cur.y] + 1;
				}

			}
			if (cur.x > 0 && dist[cur.x][cur.y] + 1 < dist[cur.x - 1][cur.y]) //up
			{
				if (!map[cur.x - 1][cur.y])
				{
					newq.push(up);
					dist[cur.x - 1][cur.y] = dist[cur.x][cur.y] + 1;
				}
			}
			if (cur.y > 0 && dist[cur.x][cur.y] + 1 < dist[cur.x][cur.y - 1]) //left
			{
				if (!map[cur.x][cur.y - 1])
				{
					newq.push(left);
					dist[cur.x][cur.y - 1] = dist[cur.x][cur.y] + 1;
				}
			}


		}
	}

	if (dist[n - 1][m - 1] == max)
		cout << -1;
	else
		cout << dist[n - 1][m - 1];
}
