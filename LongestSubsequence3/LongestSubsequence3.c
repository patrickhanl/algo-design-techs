#include <stdio.h>
#include <stdlib.h>

LenSub(int, int*, int, int*, int, int*, int***);
int maximum(int, int, int, int, int, int, int);

int main(void) {
	int first_len, second_len, third_len, *first_sequence, *second_sequence, *third_sequence, i, j, result, ***distances;

	//scan in first array
	scanf("%d", &first_len);
	first_sequence = (int *)malloc(sizeof(int)*first_len);

	for (i = 0; i < first_len; i++) {
		scanf("%d", &first_sequence[i]);
	}

	//scan in second array
	scanf("%d", &second_len);
	second_sequence = (int *)malloc(sizeof(int)*second_len);

	for (i = 0; i < second_len; i++) {
		scanf("%d", &second_sequence[i]);
	}

	//scan in third array
	scanf("%d", &third_len);
	third_sequence = (int *)malloc(sizeof(int)*third_len);

	for (i = 0; i < third_len; i++) {
		scanf("%d", &third_sequence[i]);
	}

	//create empty matrix to store distances
	distances = (int***)malloc(sizeof(int**)*(first_len + 1));
	
	//create empty second and third levels of the matrix
	for (i = 0; i < first_len + 1; i++) {
		distances[i] = (int **)malloc(sizeof(int*)*(second_len + 1));
		for (j = 0; j < second_len + 1; j++) {
			distances[i][j] = (int*)malloc(sizeof(int)*(third_len + 1));
		}
	}

	//find max matches
	result = LenSub(first_len, first_sequence, second_len, second_sequence, third_len, third_sequence, distances);

	printf("%d", result);

	free(first_sequence);
	free(second_sequence);
	free(third_sequence);
	free(distances);
}

LenSub(int first_len, int * first_sequence, int second_len, int * second_sequence, int third_len, int* third_sequence, int ***distances) {
	int i, j, k, a,b,c,d,e,f, g;

	for (j = 0; j < second_len + 1; j++) {
		for (k = 0; k < third_len + 1; k++) {
			distances[0][j][k] = 0;
		}
	}

	for (i = 1; i < first_len + 1; i++) {
		for (j = 0; j < second_len + 1; j++) {
			for (k = 0; k < third_len; k++) {
				distances[i][j][0] = 0;
				distances[i][0][k] = 0;
			}
		}
	}

	for (i = 1; i < first_len + 1; i++) {
		for (j = 1; j < second_len + 1; j++) {
			for (k = 1; k < third_len + 1; k++) {
				a = distances[i][j][k - 1];
				b = distances[i][j - 1][k];
				c = distances[i - 1][j][k];
				d = distances[i][j - 1][k - 1];
				e = distances[i - 1][j][k - 1];
				f = distances[i - 1][j - 1][k];
				g = distances[i - 1][j - 1][k - 1];

				if (first_sequence[i - 1] == second_sequence[j - 1] && second_sequence[j-1] == third_sequence[k - 1]) distances[i][j][k] = g+1;
				else distances[i][j][k] = maximum(a,b,c,d,e,f,g);
			}
		}
	}
	   
	return distances[first_len][second_len][third_len];
}

int maximum(int one, int two, int three, int four, int five, int six, int seven) {
	int result = one;

	if (two > result) result = two;
	if (three > result) result = three;
	if (four > result) result = four;
	if (five > result) result = five;
	if (six > result) result = six;
	if (seven > result) result = seven;

	return result;
}