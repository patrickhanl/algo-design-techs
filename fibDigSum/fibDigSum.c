#include <stdio.h>

int main(void) {
	long long int num;
	int first = 1, second = 1, len = 1, n, i, result = 1;
	scanf("%lld", &num);
	if (num < 2) printf("%lld", num);
	else {
		while (second != 0 || first != 1) {
			len++;
			n = (first + second) % 10;
			second = first;
			first = n;
		}
		int new_num = num % len;
		if (new_num < 2) printf("%d", new_num);
		else {
			for (i = 0; i < new_num - 1; i++) {
				n = (first + second) % 10;
				second = first;
				first = n;
				result += n;
			}
			printf("%d", result%10);
		}
	}
}