#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 105
short int map[N][N] = { 0, };
int dist[N][N] = { 0, }; // visited�� �̰ɷ� ��ü�Ѵ�. visit�� ������ ���� ���Ǵ�, �� ��ΰ� �� �ִ��ΰ�. �׷� visit �����ΰŴ�.
//�ִܰŸ� �ƴ���? ��������?
int row, col;
typedef struct _node {
	short int rowdata;
	short int coldata;
	struct _node *link;
} node;

node* headers[2500] = { NULL, };
node *front, *rear;
int convey[2] = { 0, };
void addq(int vrow, int vcol) {//rear�� �ְ�, front���� ����. �̰� queue!!
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
void deleteq() {  //front���� ����, �� node�� ���� return���ش�.
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

		if (ro > 0 && map[ro - 1][co] && dist[ro - 1][co] > dist[ro][co] + 1) //��  //���ݲ�+1 �� �� ���� distance�� �̰ɷ� ��ü �������.
		{
			addq(ro - 1, co);
			dist[ro - 1][co] = dist[ro][co] + 1;
		}
		if (ro < row - 1 && map[ro + 1][co] && dist[ro + 1][co] > dist[ro][co] + 1) //�Ʒ�
		{
			addq(ro + 1, co);
			dist[ro + 1][co] = dist[ro][co] + 1;
		}
		if (co < col - 1 && map[ro][co + 1] && dist[ro][co + 1] > dist[ro][co] + 1)  //������
		{
			addq(ro, co + 1);
			dist[ro][co + 1] = dist[ro][co] + 1;
		}
		if (co > 0 && map[ro][co - 1] && dist[ro][co - 1] > dist[ro][co] + 1)  //����
		{
			addq(ro, co - 1);
			dist[ro][co - 1] = dist[ro][co] + 1;
		}
		//����Ȱ� �Ѳ����� addq�ؾߵȴ�. ������ ������ �� �ؾߵȴٴ� ��.
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


