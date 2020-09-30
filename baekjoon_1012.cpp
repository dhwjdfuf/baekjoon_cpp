#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//���ܶ�� �Ҹ��� ���� ���̽��� �����ϱ�.
short int map[2500];

short int visited[2500] = { 0, };

typedef struct _node {
	short int data;
	struct _node *link;
} node;

node* headers[2500] = { NULL, };


void addq(int v, int addv) {//�̰� �׳� adjency list��. front�� ������ ���ݾ� ����ó��.
	//v�� addv�� �����ض�.
	node* ne;
	ne = (node*)malloc(sizeof(node*));
	ne->data = addv;

	if (!headers[v])
	{
		headers[v] = ne;
		ne->link = NULL;
	}

	else
	{
		ne->link = headers[v];
		headers[v] = ne;
	}

}

void connect(int row, int col) { //���� ����. 
	int i;
	for (i = 0; i < row*col - col; i++)//���� ����
	{
		if (map[i] && map[i + col])
		{
			addq(i, i + col);
			addq(i + col, i);
		}
	}
	for (i = 0; i < row*col - 1; i++)//���ο���
	{
		if (i%col == col - 1) continue;

		if (map[i] && map[i + 1])
		{
			addq(i, i + 1);
			addq(i + 1, i);
		}
	}
}


void dfs(int v, int row, int col) {//������ ������ ������.. �̷��� ���� ���� �༮. //�ᱹ �Ѿ�� �༮�� �װɷ� �����ϴ� ����Ʈ�� �����ϴ°Ŵ�.
	visited[v] = 1;
	node* w = headers[v];

	for (; w; w = w->link)
	{
		if (!visited[w->data]) dfs(w->data, row, col);

	}



}

void init() {
	int i;
	for (i = 0; i < 2500; i++)
	{
		map[i] = visited[i] = 0;
		headers[i] = NULL;
	}
}


int main() {
	int testcase;
	int final = 0;
	scanf("%d", &testcase);
	int i, row, col;
	int *fin;
	fin = (int*)malloc(sizeof(int)*testcase);

	for (i = 0; i < testcase; i++)
	{
		init();
		final = 0;
		int t;
		scanf("%d %d %d", &col, &row, &t);
		int k;
		for (k = 0; k < t; k++)
		{
			int first, second;
			scanf("%d %d", &first, &second); //first��  col, second�� row.
			map[second*col + first] = 1;
		}//map �Է¿Ϸ�.


		connect(row, col);

		for (k = 0; k < col*row; k++) //map�� ��� vertex�� ����, dfs �������.
		{
			if (map[k] && !visited[k])//���߰� �ְ�, �湮���� �ʾ�����, 
			{
				dfs(k, row, col);
				final++;//����� �Ѿ�Դٴ� ��, �� ���߿� ����� ���� visited ǥ�� �ƴٴ� �Ͱ� ����.���� ���� ��.
			}

		}

		fin[i] = final;

	}

	for (i = 0; i < testcase; i++)
	{
		printf("%d\n", fin[i]);
	}
	return 0;
}
