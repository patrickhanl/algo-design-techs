#include <stdio.h>
#include <stdlib.h>
struct segment {
	int start, end;
};

int main(void){
	int num_segs, i, *points, point_track = 1, end_min, end_max, start_min, start_max;
	scanf("%d", &num_segs);
	struct segment *segments;
	segments = (struct segment *)malloc(sizeof(struct segment)*num_segs);
	points = (int *)malloc(sizeof(int)*num_segs);
	for (i = 0; i < num_segs; i++) {
		scanf("%d %d", &segments[i].start, &segments[i].end);
		points[i] = -1;
	}
	end_min = end_max = segments[0].end, start_max = start_min = segments[0].start;
	for (i = 0; i < num_segs; i++) {
		if (segments[i].end < end_min) {
			end_min = segments[i].end;
		}
		if (segments[i].start > start_max) {
			start_max = segments[i].start;
		}
		if (segments[i].start < start_min) {
			start_min = segments[i].start;
		}
		if (segments[i].end > end_max) {
			end_max = segments[i].end;
		}
	}
	points[0] = end_min;
	while (start_max > end_min) {
		start_min = end_min;
		end_min = end_max;
		for (i = 0; i < num_segs; i++) {
			if (segments[i].start > start_min && segments[i].end < end_min) end_min = segments[i].end;
		}
		points[point_track] = end_min;
		point_track++;
	}
	printf("%d\n", point_track);
	for (i = 0; i < point_track; i++) printf("%d \n", points[i]);
}