#include <stdio.h>
int main() {
	int number, sum;
	sum = 0;
	scanf("%d", &number);
	for (int a = 1; a <= number; a++) {
		int  n;
		scanf("%1d", &n);

		sum += n;
	}
	printf("%d", sum);

	return 0;
}