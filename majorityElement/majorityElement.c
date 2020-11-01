#include <stdio.h>
#include <stdlib.h>

int getMajority(int * array, int array_len);

int main(void) {
	int array_len, * array, i, result;
	scanf("%d", &array_len);
	
	array = (int *) malloc(sizeof(int)*array_len);

	for (i = 0; i < array_len; i++) scanf("%d", &array[i]);
	
	result = getMajority(array, array_len);
	if (result >= 0) printf("1");
	else printf("0");
	free (array);
	return 0;
}

int getMajority(int * array, int array_len) {
	int i, left_count = 0, right_count = 0, left_element, right_element;

	if (array_len == 0)  return -1;
	if (array_len == 1) return array[0];

	left_element = getMajority(array, array_len / 2);
	if (array_len % 2 != 0) right_element = getMajority(array + (array_len / 2), (array_len / 2) +1);
	else right_element = getMajority(array + (array_len / 2), array_len / 2);

	if (left_element >= 0 && right_element >= 0 && left_element == right_element) return left_element;

	if (left_element >= 0) {
		for (i = 0; i < array_len; i++) {
			if (array[i] == left_element) left_count++;
		}
		if (left_count > array_len / 2) return left_element;
	}

	if (right_element >= 0) {
		for (i = 0; i < array_len; i++) {
			if (array[i] == right_element) right_count++;
		}
		if (right_count > array_len / 2) return right_element;
	}
	return -1;
}