#include "dictionary.h"

#include "stdio.h"
#include "stdlib.h"

typedef struct s_list_element {
    int value;
    struct s_list_element *next;
} list_element;

static list_element *dictionary[SIZE];

int calc_hash(int number) { return number % SIZE; }

int insert(int value) {
    int pos = calc_hash(value);

    list_element *new = malloc(sizeof(list_element));

    if (new == 0) return 0; 

    new->value = value;
    new->next = dictionary[pos];
    dictionary[pos] = new;

    return 1;
}

int delete_from_dict(int value) {
    int pos = calc_hash(value);

    list_element *ptr = dictionary[pos];
    list_element *previous = NULL;

    // list is empty
    if (ptr == NULL) return 0;

    // find element with value, update previous in each step
    while (ptr->value != value) {
        if (ptr->next != NULL) {
            previous = ptr;
            ptr = ptr->next;
        } else {
            return 0;
        }
    }

    if (previous == NULL) {  // first element
        dictionary[pos] = ptr->next;
    } else {
        previous->next = ptr->next;
    }
    free(ptr);

    return 1;
}

int member(int value) {
    int pos = calc_hash(value);
    list_element *ptr = dictionary[pos];

    if (ptr == NULL) return 0;

    while (ptr->value != value) {
        if (ptr->next != NULL) {
            ptr = ptr->next;
        } else {
            return 0;
        }
    }
    return 1;
}
