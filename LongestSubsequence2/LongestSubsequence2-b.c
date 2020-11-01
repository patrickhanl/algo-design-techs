#include <stdio.h>
#include <stdlib.h>

LenSub(int, int*, int, int*, int**);
int maximum(int one, int two, int three);

int main(void) {
	int first_len, second_len, *first_sequence, *second_sequence, i, result, **distances;

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

	//create empty matrix to store distances
	distances = (int**)malloc(sizeof(int*)*first_len + 1);
	for (i = 0; i < first_len + 1; i++) {
		distances[i] = (int *)malloc(sizeof(int)*(second_len + 1));
	}

	//find max matches
	result = LenSub(first_len, first_sequence, second_len, second_sequence, distances);

	printf("%d", result);

	free(first_sequence);
	free(second_sequence);
	free(distances);
}

LenSub(int first_len, int * first_sequence, int second_len, int * second_sequence, int **distances) {
	int i, j, ins, del, match, mismatch;
	
	for (i = 0; i < first_len + 1; i++) distances[i][0] = 0;

	for (j = 1; j < second_len + 1; j++) distances[0][j] = 0;

	for (j = 1; j < second_len + 1; j++) {
		for (i = 1; i < first_len + 1; i++) {
			ins = distances[i][j - 1];
			del = distances[i - 1][j];
			match = distances[i - 1][j - 1] + 1;
			mismatch = distances[i - 1][j - 1];

			if (first_sequence[i - 1] == second_sequence[j - 1]) distances[i][j] = maximum(ins, del, match);
			else distances[i][j] = maximum(ins, del, mismatch);
		}
	}
	return distances[first_len][second_len];
}

int maximum(int one, int two, int three) {
	int result = one;

	if (two > result) result = two;
	if (three > result) result = three;

	return result;
}