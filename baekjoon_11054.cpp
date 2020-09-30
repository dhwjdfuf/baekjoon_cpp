//�տ������� ����, �ڿ������� ���ҷ� �ι��ϸ� ������ ��������.
//dp�� �� ��, �迭�� �տ������� ���ʷ� �ϼ����Ѿ� �Ѵٴ� ���� ������ �̷��� �����ϰ� Ǯ�� �Ǿ��� �ž�..!
//�� �׷��� �ѹ������� õ���Ϸ������� �Ѵܰ� �����ܰ� ������ �ܰ�. ��!! �̷� �ʿ�� ���ٴ� �ž� dp��.

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
t fun(int max_index) {//max_index �յڷ� ����, ������ ���� �������ش�.
	int inc = 0, dec = 0;
	t ret;
	arr[0].length = 1;
	int i;
	for (i = 1; i <= max_index; i++) //��Ȯ��, max_index���� �����ϴ� ���������� �ִ� ���̸� ���ϴ°ž�. �ε��� 0~max_index
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
	}//incrase ��

	arr[max_index].length = 1;//���� max_index�� 0�̴�!!!
	for (i = max_index + 1; i < n; i++)//��Ȯ��, max_index���� �����ϴ� ���Ҽ����� �ִ� ���̸� ���ϴ°ž�. �ε��� max_index~n-1
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
	}//decrase ��

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
	if (arr[0].num > arr[1].num) maxs.push_back(0); //1�� 
	if (arr[n - 1].num > arr[n - 2].num) maxs.push_back(n - 1); //2��
	for (i = 1; i < n - 1; i++)
	{
		if (arr[i].num > arr[i - 1].num && arr[i].num > arr[i + 1].num) maxs.push_back(i); //3��
		if (arr[i].num > arr[i - 1].num && arr[i].num == arr[i + 1].num) maxs.push_back(i);//4��
		if (arr[i].num == arr[i - 1].num && arr[i + 1].num < arr[i].num) maxs.push_back(i);//5��
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

