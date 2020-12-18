#include <stdbool.h>
#include <stdio.h>
#define QUEUE_LENGTH 2

static int queue[QUEUE_LENGTH];
static int last = -1;
static int start = 0;

void enqueue(int i)
{
    int index = (last + 1);
    if(index < (QUEUE_LENGTH + start)) {
        queue[index % QUEUE_LENGTH] = i;
        last = index;
    } else {
        queue[last % QUEUE_LENGTH] = i;
    }
}

int dequeue()
{   
    if(last < start) return -1;

    int val = queue[start % QUEUE_LENGTH];
    start = start + 1;
    return val;
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(2);
    printf("%i ", dequeue());
    enqueue(3);
    printf("%i ", dequeue());
    printf("%i ", dequeue());
    printf("%i ", dequeue());
    enqueue(4);
    enqueue(5);
    printf("%i ", dequeue());
    printf("%i \n", dequeue());
    return 0;
}