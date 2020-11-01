#include <stdio.h>
#include <stdlib.h>

int binarySearch(int left, int sorted_array_len, int * sorted_array, int key);

int main(void) {
	int sorted_array_len, i, num_keys, key;
	int * sorted_array;

	scanf("%d", &sorted_array_len);

	sorted_array = (int *)malloc(sizeof(int)*sorted_array_len);

	for (i = 0; i < sorted_array_len; i++) scanf("%d", &sorted_array[i]);

	scanf("%d", &num_keys);
	for (i = 0; i < num_keys; i++) {
		scanf("%d", &key);
		printf("%d ", binarySearch(0, sorted_array_len, sorted_array, key));
	}

	free(sorted_array);
	return 0;
}

int binarySearch(int left, int sorted_array_len, int * sorted_array, int key) {
	if (sorted_array[sorted_array_len / 2] == key) return sorted_array_len / 2 + left;
	else if(sorted_array_len <= 1 && sorted_array[0] != key) return -1;

	else if (key < sorted_array[sorted_array_len / 2]) {
		return binarySearch(left, sorted_array_len / 2, sorted_array, key);
	}

	else if (key > sorted_array[sorted_array_len / 2]) {
		left += (sorted_array_len / 2) + 1;
		if(sorted_array_len % 2 != 0) return binarySearch(left, sorted_array_len/2, sorted_array + (sorted_array_len / 2) + 1, key);
		return binarySearch(left, (sorted_array_len / 2) - 1, sorted_array + (sorted_array_len / 2) + 1, key);
	}
}