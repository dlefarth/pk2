#include <stdio.h>

void printascii(int s) {
	int start = 32;
	int end = 126;
	for(int i = start;i <= end; i++) {
		printf("%d %c ", i, i);
		if((i - (start - 1)) %s == 0) printf("\n");	
	}		
}
