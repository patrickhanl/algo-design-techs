#include <stdio.h>

int main(void) {
	long long int start, end;
	int first = 1, second = 1, len = 1, n, i, result = 0;
	scanf("%lld %lld", &start, &end);
	if (end < 2) printf("%lld", end);
	else {
		while (second != 0 || first != 1) {
			len++;
			n = (first + second) % 10;
			second = first;
			first = n;
		}
		int new_start = start % len;
		int new_end = end % len;
		if (new_end < 2) printf("%d", new_end);
		else {
			if (new_start < 2) result += 1;
			for (i = 2; i < new_end + 1; i++) {
				n = (first + second) % 10;
				second = first;
				first = n;
				if (i > new_start-1) {
					result += n;
				}
			}
			printf("%d", result % 10);
		}
	}
}