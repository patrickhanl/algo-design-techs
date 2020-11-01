#include <stdio.h>

int main(void) {
	long long int num;
	int div, first = 1, second = 1, len = 1, n, i;
	scanf("%lld %d", &num, &div);
	if (num < 2) printf("%lld", num);
	else {
		while (second != 0 || first != 1) {
			len++;
			n = (first + second) % div;
			second = first;
			first = n;
		}
		int new_num = num % len;
		if (new_num < 2) printf("%d", new_num);
		else {
			for (i = 0; i < new_num - 1; i++) {
				n = (first + second) % div;
				second = first;
				first = n;
			}
			printf("%d", n);
		}
	}
}