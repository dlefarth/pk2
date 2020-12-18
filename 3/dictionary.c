#include "stdio.h"
#define LENGTH 2

typedef enum {FREE = 0, USED = 1, DELETED = 2} dict_state;

typedef struct {
    dict_state state;
    int value;
} dict_element;

static dict_element dictionary[LENGTH];

int calc_hash(int number) {
    return number % LENGTH;
}

int insert(int value) {
    int initialPosition = calc_hash(value);
    if(dictionary[initialPosition].state == FREE || dictionary[initialPosition].state == DELETED) {
        dictionary[initialPosition].value = value;
        dictionary[initialPosition].state = USED;
        return 1;
    } else {
        int pos = initialPosition;
        while(++pos % LENGTH != initialPosition) {
            if(dictionary[pos].state == USED && dictionary[pos].value == value) {
                return 1;
            }
            if(dictionary[pos].state == FREE || dictionary[pos].state == DELETED) {
                dictionary[pos].value = value;
                dictionary[pos].state = USED;
                return 1;
            }
        }
        return 0;
    }
}

int delete_from_dict(int value) {
    int initialPos = calc_hash(value);

    if(dictionary[initialPos].state == USED && dictionary[initialPos].value == value) {
        dictionary[initialPos].state = DELETED;
    } else {
        int pos = initialPos;
        while(++pos % LENGTH != initialPos) {
            if(dictionary[pos].state == USED && dictionary[pos].value == value) {
                dictionary[pos].state = DELETED;
                return 1;
            }
            if(dictionary[pos].state == FREE) {
                return 0;
            }
        }
        return 0;
    }
}

int member(int value) {
    int initialPos = calc_hash(value);
    if(dictionary[initialPos].state == USED && dictionary[initialPos].value == value) {
        return 1;
    } else {
        int pos = initialPos;
        while(++pos % LENGTH != initialPos) {
            if(dictionary[initialPos].state == USED && dictionary[pos].value == value) {
               return 1;
            }
            if(dictionary[initialPos].state == FREE) {
                return 0;
            }
        }
        return 0;
    }
}
