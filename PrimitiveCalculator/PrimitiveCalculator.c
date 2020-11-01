#include<stdlib.h>
#include<stdio.h>

int getMinOperations(int n, int * operations);

int main(void) {
	int n, * operations, result, i, * increments, next_n, old_n;

	scanf("%d", &n);

	operations = (int *)malloc(sizeof(int)*(n+1));

	operations[1] = 0;

	result = getMinOperations(n, operations);

	increments = (int *)malloc(sizeof(int)*result);
	increments[0] = n;

	printf("%d\n1 ", result);

	for (i = 1; i < result; i++) {
		old_n = increments[i - 1];
		next_n = increments[i-1]-1;
		if (old_n % 3 == 0) {
			if (operations[old_n / 3] < operations[next_n]) next_n = old_n / 3;
		}

		if (old_n % 2 == 0) {
			if (operations[old_n / 2] < operations[next_n]) next_n = old_n / 2;
		}
		increments[i] = next_n;
	}

	for (i = result - 1; i > -1; i--) {
		printf("%d ", increments[i]);
	}

	free(increments);
	free(operations);
}

int getMinOperations(int n, int * operations) {
	int i, two_test, three_test;
	for (i = 2; i < n+1; i++) {

		operations[i] = operations[i-1] + 1;
		if (i % 2 == 0) {
			two_test = i / 2;
			if (operations[two_test] + 1 < operations[i]) operations[i] = operations[two_test] + 1;
		}
		if (i % 3 == 0) {
			three_test = i / 3;
			if (operations[three_test] + 1 < operations[i]) operations[i] = operations[three_test] + 1;
		}
	}
	return operations[n];
}