#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//예외라고 불릴수 있을 케이스를 생각하기.
short int map[2500];

short int visited[2500] = { 0, };

typedef struct _node {
	short int data;
	struct _node *link;
} node;

node* headers[2500] = { NULL, };


void addq(int v, int addv) {//이건 그냥 adjency list야. front에 넣으면 되잖아 스택처럼.
	//v에 addv를 연결해라.
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

void connect(int row, int col) { //여기 보자. 
	int i;
	for (i = 0; i < row*col - col; i++)//세로 연결
	{
		if (map[i] && map[i + col])
		{
			addq(i, i + col);
			addq(i + col, i);
		}
	}
	for (i = 0; i < row*col - 1; i++)//가로연결
	{
		if (i%col == col - 1) continue;

		if (map[i] && map[i + 1])
		{
			addq(i, i + 1);
			addq(i + 1, i);
		}
	}
}


void dfs(int v, int row, int col) {//연결의 연결의 연결의.. 이렇게 가장 깊은 녀석. //결국 넘어가는 녀석이 그걸로 시작하는 리스트로 시작하는거다.
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
			scanf("%d %d", &first, &second); //first는  col, second는 row.
			map[second*col + first] = 1;
		}//map 입력완료.


		connect(row, col);

		for (k = 0; k < col*row; k++) //map의 모든 vertex에 대해, dfs 돌리기다.
		{
			if (map[k] && !visited[k])//배추가 있고, 방문되지 않았으면, 
			{
				dfs(k, row, col);
				final++;//여기로 넘어왔다는 건, 이 배추와 연결된 모든게 visited 표시 됐다는 것과 동일.따라서 세면 됨.
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
