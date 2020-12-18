#include <stdio.h>

void einmaleins() {
	int from;
	int to;
	printf("von: ");
	scanf("%d", &from);
	printf("bis: ");
	scanf("%d", &to);

	for(int x = 1; x <= 10; x++) {
		for(int y = from; y <= to; y++) {
			printf("%4d", x * y);
		}
		printf("\n");
	}
}
