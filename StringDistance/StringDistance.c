#include <stdio.h>
#include <stdlib.h>

int getEditDistance(char * first_word, int first_len, char* second_word, int second_len);
int minimum(int one, int two, int three);


int main(void) {
	int first_len = 0, second_len = 0, result;
	char first_word[102], second_word[102];

	scanf("%s%s", first_word, second_word);

	while (first_word[first_len] != '\0') first_len++;
	while (second_word[second_len] != '\0') second_len++;

	result = getEditDistance(first_word, first_len, second_word, second_len);

	printf("%d", result);

}

int getEditDistance(char * first_word, int first_len, char* second_word, int second_len) {

	int ** distances, i, j, ins, del, match, mismatch, result;

	distances = (int **)malloc(sizeof(int *)*(first_len + 1));

	for (i = 0; i < first_len + 1; i++) {
		distances[i] = (int *)malloc(sizeof(int)*(second_len + 1));
	}

	for (i = 0; i < first_len + 1; i++) distances[i][0] = i;

	for (j = 1; j < second_len + 1; j++) distances[0][j] = j;

	for (j = 1; j < second_len + 1; j++) {
		for (i = 1; i < first_len + 1; i++) {
			ins = distances[i][j - 1] + 1;
			del = distances[i - 1][j] + 1;
			match = distances[i - 1][j - 1];
			mismatch = distances[i - 1][j - 1] + 1;

			if (first_word[i-1] == second_word[j-1]) distances[i][j] = minimum(ins, del, match);
			else distances[i][j] = minimum(ins, del, mismatch);
		}
	}

	result = distances[first_len][second_len];
	
	free(distances);

	return result;

}

int minimum(int one, int two, int three) {
	int result = one;

	if (two < result) result = two;
	if (three < result) result = three;

	return result;
}