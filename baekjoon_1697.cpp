#include <iostream>
using namespace std;
#include <queue>
#define max 100001
typedef struct {
	int dist;
	int place;
}node;
node arr[max];
bool visited[max] = { 0, };
int main() {
	int start, dest;
	cin >> start >> dest;
	if (dest < start)
	{
		cout << start - dest;
		return 0;
	}
	queue <node> q;

	node head;
	head.dist = 0;
	head.place = start;
	visited[start] = 1;

	q.push(head);
	int i;
	for (;;)
	{
		node cur = q.front();
		q.pop();

		if (cur.place == dest)
		{
			cout << cur.dist;
			return 0;
		}

		node minus_one;
		node plus_one;
		node multi_two;

		minus_one.dist = cur.dist + 1;
		minus_one.place = cur.place - 1;

		plus_one.dist = cur.dist + 1;
		plus_one.place = cur.place + 1;

		multi_two.dist = cur.dist + 1;
		multi_two.place = cur.place * 2;

		if (cur.place >= 1 && cur.place <= max / 2) //-1��, +1��, ���ϱ� 2�� �Ǵ� ���
		{
			if (!visited[cur.place - 1])
			{
				q.push(minus_one);
				visited[cur.place - 1] = 1;
			}
			if (!visited[cur.place + 1])
			{
				q.push(plus_one);
				visited[cur.place + 1] = 1;
			}
			if (!visited[cur.place * 2])
			{
				q.push(multi_two);
				visited[cur.place * 2] = 1;
			}



		}
		else if (cur.place == 0) //+1, ���ϱ� 2 ����
		{


			if (!visited[cur.place + 1])
			{
				q.push(plus_one);
				visited[cur.place + 1] = 1;
			}
			if (!visited[cur.place * 2])
			{
				q.push(multi_two);
				visited[cur.place * 2] = 1;
			}

		}
		else if (cur.place > max / 2 && cur.place < max) //+1 -1 ����
		{

			if (!visited[cur.place - 1])
			{
				q.push(minus_one);
				visited[cur.place - 1] = 1;
			}
			if (!visited[cur.place + 1])
			{
				q.push(plus_one);
				visited[cur.place + 1] = 1;
			}


		}
		else if (cur.place == max) //-1�� ����
		{
			if (!visited[cur.place - 1])
			{
				q.push(minus_one);
				visited[cur.place - 1] = 1;
			}

		}

	}
}