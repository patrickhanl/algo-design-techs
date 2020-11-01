#include <stdio.h>
#include <stdlib.h>

int getInversions(int *, int *, int, int);

int main(void) {
	int array_len, * array, *sorted_array, i;
	
	scanf("%d", &array_len);
	array = (int *)malloc(sizeof(int) * array_len);
	sorted_array = (int *)malloc(sizeof(int) * array_len);
	
	for (i = 0; i < array_len; i++) scanf("%d", &array[i]);

	printf("%d", getInversions(array, sorted_array, 0, array_len - 1));

	//for (i = 0; i < array_len; i++) printf("%d ", array[i]);

	free(sorted_array);
	free(array);
}

int getInversions(int * array, int * sorted_array, int left, int right) {
	int num_inversions = 0, left_track = left, mid = left + (right - left) / 2, right_track = mid + 1, i;
	if (left >= right) return num_inversions;

	num_inversions += getInversions(array, sorted_array, left, mid);
	num_inversions += getInversions(array, sorted_array, mid + 1, right);

	for (i = left; i < right + 1; i++) {

		if (right_track > right) {
			sorted_array[i] = array[left_track];
			left_track++;
		}

		else if (left_track > mid) {
			sorted_array[i] = array[right_track];
			right_track++;
		}

		else if (array[left_track] <= array[right_track]) {
			sorted_array[i] = array[left_track];
			left_track++;
		}

		else if (array[left_track] > array[right_track]) {
			sorted_array[i] = array[right_track];
			num_inversions += (mid + 1) - left_track;
			right_track++;
		}
	}

	for (i = left; i < right + 1; i++) {
		array[i] = sorted_array[i];
	}

	return num_inversions;
}
