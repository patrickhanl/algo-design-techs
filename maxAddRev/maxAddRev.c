#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int len, i, j, first_mark, second_mark;
	long long int * first, * second;
	long long int first_max, second_max, result = 0;
	scanf("%d", &len);
	first = (long long int*)malloc(sizeof(long long int)*len);
	second = (long long int*)malloc(sizeof(long long int)*len);
	for (i = 0; i < len; i++) scanf("%lld", &first[i]);
	for (i = 0; i < len; i++) scanf("%lld", &second[i]);
	for (i = 0; i < len; i++){
		first_max = first[0];
		second_max = second[0];
		first_mark = 0;
		second_mark = 0;
		for (j = 0; j < len; j++) {
			if (first[j] > first_max) {
				first_max = first[j];
				first_mark = j;
			}
			if (second[j] > second_max) {
				second_max = second[j];
				second_mark = j;
			}
		}
		first[first_mark] = -10000000;
		second[second_mark] = -1000000;
		result += first_max * second_max;
	}
	printf("%lld", result);
	free(first);
	free(second);
}