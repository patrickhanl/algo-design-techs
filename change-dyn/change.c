#include <stdio.h>
#include <stdlib.h>

int minCoins(int * coins, int num_coins, int money, int * min_num_coins);

int main(void) {
	int coins[3] = { 1,3,4 }, num_coins = 3, money, result;

	scanf("%d", &money);
	if (money <= coins[0]) {
		printf("%d", money);
		return 0;
	}
	int * min_num_coins = (int *)malloc(sizeof(int)*(money+1));
	min_num_coins[0] = 0;

	result = minCoins(coins, num_coins, money, min_num_coins);

	printf("%d", result);

	free(min_num_coins);
}

int minCoins(int * coins, int num_coins, int money, int * min_num_coins) {
	int m,i, coin_count;
	for (m = 1; m <= money; m++) {
		min_num_coins[m] = money + 1;
		for (i = 0; i < num_coins; i++) {
			if (m >= coins[i]) {
				coin_count = min_num_coins[m - coins[i]] + 1;
				if (coin_count < min_num_coins[m]) min_num_coins[m] = coin_count;
			}
		}
	}
	return min_num_coins[money];

}