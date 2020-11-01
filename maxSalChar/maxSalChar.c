#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int greaterOrEqual(int test, int current);

int main(void) {
	int i, num_digits, j, max_digit, max_index;
	int * digits, *result;

	scanf("%d", &num_digits);

	digits = (int *)malloc(sizeof(int)*num_digits);
	result = (int *)malloc(sizeof(int)*num_digits);

	for (i = 0; i < num_digits; i++) scanf("%d", &digits[i]);

	for (i = 0; i < num_digits; i++) {
		max_digit = 0;
		for (j = 0; j < num_digits; j++) {
			if (greaterOrEqual(digits[j], max_digit)) {
				max_digit = digits[j];
				max_index = j;
			}
		}
		result[i] = max_digit;
		digits[max_index] = 0;
	}
	for (i = 0; i < num_digits; i++) printf("%d", result[i]);
	free(digits);
}

int greaterOrEqual(int test, int current) {

	int test_plus_current = 0, current_plus_test = 0;
	char * test_str, * current_str, * test_plus_current_str, * current_plus_test_str;

	int test_digits = (int)log10(test) + 1;
	int current_digits = (int)log10(current) + 1;

	if (test == 0) test_digits = 1;
	if (current == 0) current_digits = 1;

	test_str = (char *)malloc(sizeof(char)*test_digits + 1);
	current_str = (char *)malloc(sizeof(char)*current_digits + 1);

	test_plus_current_str = (char *)malloc(sizeof(char)*(test_digits + current_digits + 1));
	current_plus_test_str = (char *)malloc(sizeof(char)*(test_digits + current_digits + 1));

	sprintf(test_str, "%d", test);
	sprintf(current_str, "%d", current);

	strcpy(test_plus_current_str, test_str);
	strcat(test_plus_current_str, current_str);

	strcpy(current_plus_test_str, current_str);
	strcat(current_plus_test_str, test_str);

	sscanf(test_plus_current_str, "%d", &test_plus_current);
	sscanf(current_plus_test_str, "%d", &current_plus_test);

	free(current_plus_test_str);
	free(test_plus_current_str);

	free(test_str);
	free(current_str);

	return test_plus_current >= current_plus_test;

}