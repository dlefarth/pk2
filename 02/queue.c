#include <stdbool.h>
#include <stdio.h>
#define SIZE 2

int queue[SIZE];
int last = -1;
int start = 0;

void enqueue(int i) {
    if ((last - start) + 1 < SIZE) {
        last++;
        queue[last % SIZE] = i;
    } else {
        queue[last % SIZE] = i;
    }
}

int dequeue() {
    if (last < start) return -1;

    int val = queue[start % SIZE];
    start++;
    return val;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(2);
    printf("%i", dequeue());
    enqueue(3);
    printf("%i", dequeue());
    printf("%i", dequeue());
    printf("%i", dequeue());
    enqueue(4);
    enqueue(5);
    printf("%i", dequeue());
    printf("%i", dequeue());
    return 0;
}
