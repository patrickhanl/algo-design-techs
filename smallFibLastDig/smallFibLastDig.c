#include <stdlib.h>
#include <stdio.h>

int main(void){
	int num;
	scanf("%d", &num);
	int n, n1 = 1, n2 = 0, i;
	for (i = 0; i < num - 1; i++) {
		n = (n1 + n2) % 10;
		n2 = n1;
		n1 = n;
	}
	printf("%d", n);
	return 0;
}