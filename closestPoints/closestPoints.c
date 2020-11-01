#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double findDistance(int x1, int x2, int y1, int y2);
double minDistance(int * x, int * y, int num_points);
void randomized_quick_sort(int * array, int * array2, int l, int r);
int * partition_3(int * array, int * array2, int l, int r);
void swap(int * array, int first, int second);
double greater(double, double);
double less(double, double);

int main(void) {
	int num_points, i, *x, *y, xmax = -1000000001, xmin = 1000000001, ymax = -1000000001, ymin = 1000000001;
	double result;
	scanf("%d", &num_points);

	x = (int *)malloc(sizeof(int) * num_points);
	y = (int *)malloc(sizeof(int) * num_points);


	for (i = 0; i < num_points; i++) {
		scanf("%d %d", &x[i], &y[i]);
		if (x[i] > xmax) xmax = x[i];
		if (x[i] < xmin) xmin = x[i];
		if (y[i] > ymax) ymax = y[i];
		if (y[i] < ymin) ymin = y[i];
	}

	randomized_quick_sort(x, y, 0, num_points - 1);

	result = minDistance(x, y, num_points);
	printf("%lf", result);

	free(x);
	free(y);

	return result;
}

//Distance function between two points
double findDistance(int x1, int x2, int y1, int y2) {
	return sqrt(pow((double)(x1 - x2), 2) + pow((double)(y1 - y2), 2));
}

//recursive min distance between group of points
double minDistance(int *x, int *y, int num_points) {
	double min_distance, dist_1, dist_2;

	//base cases
	if (num_points < 2) {
		return -1.0;
	}

	if (num_points == 2) {
		return findDistance(x[0], x[1], y[0], y[1]);
	}

	//recursive calls
	int mid = num_points / 2;

	dist_1 = minDistance(x, y, mid);

	if (num_points % 2) {
		dist_2 = minDistance(x + mid, y + mid, mid + 1);
	} else {
		dist_2 = minDistance(x + mid, y + mid, mid);
	}

	if (dist_1 < 0 || dist_2 < 0) min_distance = greater(dist_1, dist_2);
	else min_distance = less(dist_1, dist_2);

	//get subset of points with x distance to middle line < minimum distance if any
	int i, j, *x_subset, *y_subset, subset_count = 0;

	y_subset = (int *)malloc(sizeof(int) * num_points);
	x_subset = (int *)malloc(sizeof(int) * num_points);

	//double comparison
	for (i = 0; i < num_points; i++) {
		if (fabs((double)x[i] - x[mid]) < min_distance) {
			y_subset[subset_count] = y[i];
			x_subset[subset_count] = x[i];
			subset_count++;
		}
	}

	if (subset_count == 0) return min_distance;

	double dist_track;

	randomized_quick_sort(y_subset, x_subset, 0, subset_count - 1);

	for (i = 0; i < subset_count - 1; i++) {
		for (j = i+1; j < i+8; j++) {
			if (j > subset_count - 1) break;
			dist_track = findDistance(x_subset[i], x_subset[j], y_subset[i], y_subset[j]);
			if (dist_track < min_distance) min_distance = dist_track;
		}
	}

	return min_distance;
}

double greater(double a, double b) {
	if (a >= b) return a;
	else return b;
}

double less(double a, double b) {
	if (a <= b) return a;
	else return b;
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