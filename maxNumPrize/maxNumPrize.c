#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, num, sum_prizes = 1, places = 1, tmp;
	int *prizes;

	scanf("%d", &num);
	prizes = (int *)malloc(sizeof(int)*num);
	prizes[0] = 1;
	if (num == 2) {
		sum_prizes = 2;
		prizes[0] = 2;
	}
	while (sum_prizes < num) {
		tmp = prizes[places - 1] + 1;
		if (num - (sum_prizes + tmp) >= tmp +1) {
			prizes[places] = tmp;
		} else {
			prizes[places] = num - sum_prizes;
		}
		sum_prizes += prizes[places];
		places++;
	}
	printf("%d\n", places);
	for (i = 0; i < places; i++) printf("%d ", prizes[i]);
	return 0;
}