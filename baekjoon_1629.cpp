#include <iostream>
using namespace std;
int c;
unsigned long long fun(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;

	unsigned long long temp = fun(a, b / 2) % c;

	if (b % 2 == 1) return (((temp * temp) % c) * (a%c)) % c;
	else
	{
		return (temp * temp) % c;

	}


	//temp가 점점 1 2 4 8 16 이렇게 되는거다. 마지막 temp를 최종적으로 리턴하게 되는거지.

	//(a*b)%c=((a%c)*(b%c)) % c  이것만..!!!!!!!!!!!
}
int main() {
	int a, b;
	cin >> a >> b >> c;

	unsigned long long ttemp = fun(a%c, b);
	cout << ttemp % c;


}