#include <stdio.h>
#include <stdlib.h>

void randomized_quick_sort(int * array, int l, int r);
int * partition_3(int * array, int l, int r);
void swap(int * array, int first, int second);

int main(void) {
	int n, * array, i;

	scanf("%d", &n);
	array = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) scanf("%d", &array[i]);

	randomized_quick_sort(array, 0, n - 1);

	for (i = 0; i < n; i++) printf("%d ", array[i]);
}

void randomized_quick_sort(int * array, int l, int r) {
	if (l >= r) return;

	int k = rand() % (r + 1 - l) + l;
	swap(array, l, k);
	int * m = partition_3(array, l, r);

	randomized_quick_sort(array, l, m[0] - 1);
	randomized_quick_sort(array, m[1], r);

}

void swap(int * array, int first, int second) {
	int j = array[first];
	array[first] = array[second];
	array[second] = j;
}

int * partition_3(int * array, int l, int r) {
	int k = array[l];
	int i, m1 = l + 1, m2 = l + 1;
	for (i = l + 1; i < r + 1; i++) {
		if (array[i] < k) {
			swap(array, i, m1);
			if (m1 != m2) swap(array, i, m2);
			m1++;
			m2++;
		}
		else if (k == array[i]) {
			swap(array, i, m2);
			m2++;
		}
	}
	swap(array, l, m1 - 1);
	int * m = (int *)malloc(sizeof(int) * 2);
	m1 -= 1;
	m[0] = m1;
	m[1] = m2;
	return m;
}