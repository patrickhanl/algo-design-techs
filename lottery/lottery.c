#include <stdio.h>
#include <stdlib.h>

int segsContainingPoint(int point, int * starts, int * ends, int num_segments);
void randomized_quick_sort(int * array, int * array2, int l, int r);
int * partition_3(int * array, int * array2, int l, int r);
void swap(int * array, int first, int second);
int findStart(int point, int * starts, int left, int num_segments);
int findEnd(int point, int left, int right, int * ends);
int endSearch(int point, int * sorted_ends, int left, int right);

int main(void) {
	int num_segments, num_points, i, * starts, * ends, * points, * counts;

	scanf("%d%d", &num_segments, &num_points);

	starts = (int *) malloc(sizeof(int) * num_segments);
	ends = (int *) malloc(sizeof(int) * num_segments);

	points = (int *) malloc(sizeof(int) * num_points);
	counts = (int *)malloc(sizeof(int) * num_points);

	for (i = 0; i < num_segments; i++) scanf("%d%d", &starts[i], &ends[i]);
	for (i = 0; i < num_points; i++) scanf("%d", &points[i]);

	randomized_quick_sort(starts, ends, 0, num_segments - 1);

	for (i = 0; i < num_points; i++) {
		printf("%d ", segsContainingPoint(points[i], starts, ends, num_segments));
	}

	free(starts);
	free(ends);
	free(points);
	free(counts);
}

int segsContainingPoint(int point, int * starts, int * ends, int num_segments) {
	int totalSegs = 0, start, end;
	start = findStart(point, starts, 0, num_segments - 1);
	if (start == -1) return 0;
	end = findEnd(point, 0, start, ends);
	if (end == -1) return 0;
	return end;
	
}

int findStart(int point, int * starts, int left, int right) {
	int mid = left + (right - left) / 2;

	if (starts[0] > point) return -1;
	if (starts[right] <= point) return right;
	
	if (starts[mid] <= point && starts[mid + 1] > point) return  mid;

	else if (starts[mid] > point) {
		return findStart(point, starts, left, mid - 1);
	}

	else if (starts[mid] <= point) {
		return findStart(point, starts, mid + 1, right);
	}
}

findEnd(int point, int left, int right, int * ends) {
	int * sorted_ends, i, new_len, result;
	new_len = right - left + 1;
	sorted_ends = (int *)malloc(sizeof(int) * new_len);
	for (i = 0; i < new_len; i++) {
		sorted_ends[i] = ends[i];
	}
	randomized_quick_sort(sorted_ends, NULL, 0, right);

	result = endSearch(point, sorted_ends, 0, new_len - 1);

	free(sorted_ends);

	if (result == -1) return -1;

	return new_len - result;
}

int endSearch(int point, int * sorted_ends, int left, int right) {
	int mid = left + (right - left) / 2;

	if (point > sorted_ends[right]) return -1;
	if (point <= sorted_ends[0]) return 0;

	if (sorted_ends[mid] >= point && sorted_ends[mid - 1] < point) return mid;

	else if (sorted_ends[mid] >= point) {
		return endSearch(point, sorted_ends, left, mid - 1);
	}

	else if (sorted_ends[mid] < point) {
		return endSearch(point, sorted_ends, mid + 1, right);
	}
}


void randomized_quick_sort(int * array, int * array2, int l, int r) {
	if (l >= r) return;

	int k = rand() % (r + 1 - l) + l;
	swap(array, l, k);
	swap(array2, l, k);
	int * m = partition_3(array, array2, l, r);

	randomized_quick_sort(array, array2, l, m[0] - 1);
	randomized_quick_sort(array, array2, m[1], r);

}

void swap(int * array, int first, int second) {
	if (array != NULL) {
		int j = array[first];
		array[first] = array[second];
		array[second] = j;
	}
}

int * partition_3(int * array, int * array2, int l, int r) {
	int k = array[l];
	int i, m1 = l + 1, m2 = l + 1;
	for (i = l + 1; i < r + 1; i++) {
		if (array[i] < k) {
			swap(array, i, m1);
			swap(array2, i, m1);
			if (m1 != m2) {
				swap(array, i, m2);
				swap(array2, i, m2);
			}
			m1++;
			m2++;
		}
		else if (k == array[i]) {
			swap(array, i, m2);
			swap(array2, i, m2);
			m2++;
		}
	}

	swap(array, l, m1 - 1);
	swap(array2, l, m1 - 1);
	int * m = (int *)malloc(sizeof(int) * 2);
	m1 -= 1;
	m[0] = m1;
	m[1] = m2;
	return m;
}