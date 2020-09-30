//앞에서부터 증가, 뒤에서부터 감소로 두번하면 끝나는 문제였다.
//dp를 할 때, 배열을 앞에서부터 차례로 완성시켜야 한다는 생각 때문에 이렇게 난해하게 풀게 되었던 거야..!
//꼭 그렇게 한방향으로 천편일률적으로 한단계 다음단계 마지막 단계. 끝!! 이럴 필요는 없다는 거야 dp가.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct {
	int num;
	int length;
}item;
typedef struct {
	int final_answer;
	int updown_flag;
}t;
int n;
int flag = 0;
item arr[1000];
t fun(int max_index) {//max_index 앞뒤로 증가, 감소의 합을 리턴해준다.
	int inc = 0, dec = 0;
	t ret;
	arr[0].length = 1;
	int i;
	for (i = 1; i <= max_index; i++) //적확히, max_index까지 포함하는 증가수열의 최대 길이를 원하는거야. 인덱스 0~max_index
	{
		int j;

		arr[i].length = 1;

		for (j = 0; j < i; j++)
		{
			if (arr[i].num > arr[j].num && arr[j].length + 1 > arr[i].length)
			{
				arr[i].length = arr[j].length + 1;
			}

			if (arr[i].length > inc) inc = arr[i].length;
		}
	}//incrase 끝

	arr[max_index].length = 1;//이제 max_index가 0이다!!!
	for (i = max_index + 1; i < n; i++)//적확히, max_index까지 포함하는 감소수열의 최대 길이를 원하는거야. 인덱스 max_index~n-1
	{
		int j;

		arr[i].length = 1;

		for (j = max_index; j < i; j++)
		{
			if (arr[i].num < arr[j].num && arr[j].length + 1 > arr[i].length)
			{
				arr[i].length = arr[j].length + 1;
			}

			if (arr[i].length > dec) dec = arr[i].length;
		}
	}//decrase 끝

	if (inc == 0 || dec == 0) ret.updown_flag = 0;
	else ret.updown_flag = 1;

	ret.final_answer = inc + dec;

	return ret;
}
int main() {
	cin >> n;
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i].num;
	}
	if (n == 1) { cout << 1; return 0; }

	vector <int> maxs;
	if (arr[0].num > arr[1].num) maxs.push_back(0); //1번 
	if (arr[n - 1].num > arr[n - 2].num) maxs.push_back(n - 1); //2번
	for (i = 1; i < n - 1; i++)
	{
		if (arr[i].num > arr[i - 1].num && arr[i].num > arr[i + 1].num) maxs.push_back(i); //3번
		if (arr[i].num > arr[i - 1].num && arr[i].num == arr[i + 1].num) maxs.push_back(i);//4번
		if (arr[i].num == arr[i - 1].num && arr[i + 1].num < arr[i].num) maxs.push_back(i);//5번
	}
	if (!maxs.size()) { cout << 1; return 0; }

	t ans;
	ans.final_answer = 1;
	for (i = 0; i < maxs.size(); i++)
	{
		t temp = fun(maxs[i]);
		if (temp.final_answer > ans.final_answer) ans = temp;
	}

	if (ans.updown_flag) cout << ans.final_answer - 1;
	else cout << ans.final_answer;
}

