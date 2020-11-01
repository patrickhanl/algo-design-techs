#include <stdio.h>
#include <stdlib.h>

int best(int num_items, int * item_values, int * item_weights);

int main(void) {
	int num_items, capacity, i, best_item;
	double total_value = 0;
	scanf("%d %d", &num_items, &capacity);
	int *item_values = (int *)malloc(sizeof(int)*num_items);
	int *item_weights = (int *)malloc(sizeof(int)*num_items);
	for (i = 0; i < num_items; i++) {
		scanf("%d %d", &item_values[i], &item_weights[i]);
	}

	while (capacity > 0) {
		best_item = best(num_items, item_values, item_weights);
		if (best_item == -1) break;
		else if (capacity >= item_weights[best_item]) {
			capacity -= item_weights[best_item];
			total_value += item_values[best_item];
			item_weights[best_item] = 0;
		}
		else {
			total_value += capacity * ((double)item_values[best_item] / item_weights[best_item]);
			capacity = 0;
		}
	}
	printf("%.4f", total_value);
}

int best(int num_items, int * item_values, int * item_weights) {
	int i, max_val[2] = { 0,0 }, best_item = -1;
	for (i = 0; i < num_items; i++) {
		if (item_weights[i] > 0 && max_val[1] == 0 && max_val[0] == 0) {
			best_item = i;
			max_val[0] = item_values[i];
			max_val[1] = item_weights[i];
		}
		else if (item_weights[i] > 0 && item_values[i]*max_val[1]>item_weights[i]*max_val[0]) {
			best_item = i;
			max_val[0] = item_values[i];
			max_val[1] = item_weights[i];
		}
	}
	return best_item;
}