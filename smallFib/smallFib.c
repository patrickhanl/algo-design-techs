#include <stdio.h>
#include <stdlib.h>

int simpleFib(int num);

int main(void) {
	int fib;
	scanf("%d", &fib);
	printf("%d", simpleFib(fib));
	return 0;
}

int simpleFib(int num) {
	if (num < 2) return num;
	int n, n1 = 1, n2 = 0, i;
	for (i = 0; i < num-1; i++) {
		n = n1 + n2;
		n2 = n1;
		n1 = n;
	}
	return n;
}