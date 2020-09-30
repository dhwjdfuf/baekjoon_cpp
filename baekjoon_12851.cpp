#include <iostream>
using namespace std;
#include <queue>
#define max 100001
#define INT_MAX 1000002


int dist[max];
int ans[max] = { 0, };



int main() {
	int start, dest;
	int i;
	cin >> start >> dest;

	for (i = 0; i < max; i++)
		dist[i] = INT_MAX;
	dist[start] = 0;
	ans[start] = 1;			//�������, �ʱ�ȭ


	queue <int> q;
	q.push(start);


	for (;;)
	{
		if (q.empty()) break;
		int cur = q.front();
		q.pop();






		if (cur >= 1 && cur <= max / 2) //-1��, +1��, ���ϱ� 2�� �Ǵ� ���
		{
			if (dist[cur - 1] >= dist[cur] + 1)
			{
				q.push(cur - 1);
				dist[cur - 1] = dist[cur] + 1;
				ans[cur - 1]++;

			}
			if (dist[cur + 1] >= dist[cur] + 1)
			{
				q.push(cur + 1);
				dist[cur + 1] = dist[cur] + 1;
				ans[cur + 1]++;

			}
			if (dist[cur * 2] >= dist[cur] + 1)
			{
				q.push(cur * 2);
				dist[cur * 2] = dist[cur] + 1;
				ans[cur * 2]++;
			}



		}
		else if (cur == 0) //+1, ���ϱ� 2 ����
		{
			if (dist[cur + 1] >= dist[cur] + 1)
			{
				q.push(cur + 1);
				dist[cur + 1] = dist[cur] + 1;
				ans[cur + 1]++;

			}
			if (dist[cur * 2] >= dist[cur] + 1)
			{
				q.push(cur * 2);
				dist[cur * 2] = dist[cur] + 1;
				ans[cur * 2]++;
			}

		}
		else if (cur > max / 2 && cur < max) //+1 -1 ����
		{

			if (dist[cur - 1] >= dist[cur] + 1)
			{
				q.push(cur - 1);
				dist[cur - 1] = dist[cur] + 1;
				ans[cur - 1]++;

			}
			if (dist[cur + 1] >= dist[cur] + 1)
			{
				q.push(cur + 1);
				dist[cur + 1] = dist[cur] + 1;
				ans[cur + 1]++;

			}


		}
		else if (cur == max) //-1�� ����
		{
			if (dist[cur - 1] >= dist[cur] + 1)
			{
				q.push(cur - 1);
				dist[cur - 1] = dist[cur] + 1;
				ans[cur - 1]++;

			}

		}



	}
	cout << dist[dest] << endl << ans[dest];
}