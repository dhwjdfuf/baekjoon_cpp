#include <iostream>
#include <vector>
using namespace std;
#include <stack>
#include <algorithm>

int n, length;
stack <int> st;
typedef struct {
	int cnt;
	int visited[9];
	vector <int> ans;

}node;
node head = { 0, };

void dfs(node cur) { //최초의 cur은, ans가 없는 애. 이는 이대로 유지해야해.

	if (cur.cnt == length)
	{
		int i;
		for (i = 0; i < length; i++)
		{
			cout << cur.ans[i] << ' ';
		}
		cout << '\n';

		return;
	}

	int i;
	for (i = 1; i <= n; i++)
	{
		if (!cur.visited[i])
		{
			//cur.visited[i] = 1;  
			//내가 visited를 newnode 뒤에 넣어야되나? 라고 생각하게된 이유가 이거야. 근데 dfs라는 생각에 생각도 안하고 넣었던거야.

			node newnode;

			newnode.cnt = cur.cnt + 1;

			newnode.ans.assign(9, 0);//이렇게 할당해주는게 있어야 밑에서 copy 가능.

			copy(cur.visited, cur.visited + 9, newnode.visited);  //newnode에 visited 복사
			newnode.ans.assign(cur.ans.begin(), cur.ans.end()); //복사
			newnode.ans.push_back(i);

			dfs(newnode);
		}
	}

}
void init() {

}
int main() {
	cin >> n >> length;
	int i, j;

	head.cnt = 0;
	dfs(head);


}

