#include <stdio.h>

char to_upper_case(char c) {
	return c - 32;	
}

void upper(char text[]) {
	for(int i = 0; text[i] != '\0'; i++) {
		printf("%c", to_upper_case(text[i]));
	}
}
