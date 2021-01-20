#include "dictionary.h"
#include <stdio.h>

int main()
{
    printf("%d\n", insert(1));
    printf("%d\n", insert(3));
    printf("%d\n", delete_from_dict(3));
    printf("%d\n", insert(5));
    printf("%d\n", member(5));
    return 0;
}