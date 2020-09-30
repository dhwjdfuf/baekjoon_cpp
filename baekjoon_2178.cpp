#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 105
short int map[N][N] = { 0, };
int dist[N][N] = { 0, }; // visited를 이걸로 대체한다. visit이 가능한 가의 정의는, 내 경로가 더 최단인가. 그럼 visit 가능인거다.
//최단거리 아니쥬? 개판이쥬?
int row, col;
typedef struct _node {
	short int rowdata;
	short int coldata;
	struct _node *link;
} node;

node* headers[2500] = { NULL, };
node *front, *rear;
int convey[2] = { 0, };
void addq(int vrow, int vcol) {//rear에 넣고, front에서 뺀다. 이게 queue!!
	node* new;
	new = (node*)malloc(sizeof(node*));
	new->rowdata = vrow;
	new->coldata = vcol;

	new->link = NULL;

	if (!rear)
	{
		front = rear = new;
	}
	else
	{
		rear->link = new;
		rear = new;
	}

}
void deleteq() {  //front에서 빼서, 뺀 node의 값을 return해준다.
	convey[0] = front->rowdata;
	convey[1] = front->coldata;
	if (front == rear)
	{
		if (!front) free(front);
		front = rear = NULL;
		return;
	}
	node *temp = front;
	front = front->link;
	if (!front)	free(temp);

	return;

}


void bfs() { //iteration
	addq(0, 0);
	dist[0][0] = 1;
	int ro, co;
	for (; front;)
	{
		deleteq();
		ro = convey[0];
		co = convey[1];

		if (ro == row - 1 && co == col - 1) break;

		if (ro > 0 && map[ro - 1][co] && dist[ro - 1][co] > dist[ro][co] + 1) //위  //지금꺼+1 이 더 작은 distance면 이걸로 교체 시켜줘요.
		{
			addq(ro - 1, co);
			dist[ro - 1][co] = dist[ro][co] + 1;
		}
		if (ro < row - 1 && map[ro + 1][co] && dist[ro + 1][co] > dist[ro][co] + 1) //아래
		{
			addq(ro + 1, co);
			dist[ro + 1][co] = dist[ro][co] + 1;
		}
		if (co < col - 1 && map[ro][co + 1] && dist[ro][co + 1] > dist[ro][co] + 1)  //오른쪽
		{
			addq(ro, co + 1);
			dist[ro][co + 1] = dist[ro][co] + 1;
		}
		if (co > 0 && map[ro][co - 1] && dist[ro][co - 1] > dist[ro][co] + 1)  //왼쪽
		{
			addq(ro, co - 1);
			dist[ro][co - 1] = dist[ro][co] + 1;
		}
		//연결된거 한꺼번에 addq해야된다. 가능한 모든방향 다 해야된다는 것.
	}

	;

}


int main() {

	int i, j;

	scanf("%d %d", &row, &col);

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			scanf("%1d", &map[i][j]);
			dist[i][j] = row * col;
		}
	}
	bfs();
	printf("%d", dist[row - 1][col - 1]);

	return 0;
}


