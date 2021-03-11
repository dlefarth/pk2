#include "stdio.h"
#define LENGTH 2

typedef enum {FREE = 0, USED = 1, DELETED = 2} dict_state;

typedef struct {
    dict_state state;
    int value;
} dict_element;

dict_element dictionary[LENGTH];

int calc_hash(int number) {
    return number % LENGTH;
}

int insert(int value) {
    int pos = calc_hash(value);
    if(dictionary[pos].state == FREE || dictionary[pos].state == DELETED) {
		dictionary[pos] = (dict_element) {USED, value};
        return 1;
    } else {
        int initialPos = pos;
        while(++pos % LENGTH != initialPos) {
            if(dictionary[pos].state == USED && dictionary[pos].value == value) {
                return 1;
            }
            if(dictionary[pos].state == FREE || dictionary[pos].state == DELETED) {
				dictionary[pos] = (dict_element) {USED, value};
                return 1;
            }
        }
        return 0;
    }
}

int delete_from_dict(int value) {
    int pos = calc_hash(value);

    if(dictionary[pos].state == USED && dictionary[pos].value == value) {
        dictionary[pos].state = DELETED;
    } else {
        int initialPos = pos;
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
    int pos = calc_hash(value);
    if(dictionary[pos].state == USED && dictionary[pos].value == value) {
        return 1;
    } else {
        int initialPos = pos;
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

