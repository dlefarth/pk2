#include <stdio.h>
#include <math.h>

const int BITS = 16;

void print_as_binary(unsigned short decimal) {
		for(int i = BITS; i > 0; i--) {
			int res = pow(2,(i-1));
			if(decimal - res >= 0) {
				printf("1");
				decimal -= res;
			}
			else {
				printf("0");
			}
		}
}

