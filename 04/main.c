#include "dictionary.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        insert(atoi(argv[i]));
    }

    while (1) {
        int input;
        scanf("%d", &input);
        if (input != -1) {
            printf("%d", member(input));
        } else {
            break;
        }
    }
}