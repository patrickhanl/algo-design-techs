#include <stdio.h>

int main(void){
	int total, coins = 0, i;
	int denoms[] = { 10,5,1 };
	scanf("%d", &total);
	for (i = 0; i < 3; i++) {
		coins += total / denoms[i];
		total = total % denoms[i];
	}
	printf("%d", coins);
}