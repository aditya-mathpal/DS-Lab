#include "stack.h"

typedef struct {
    stack s1,s2;
}staqueue;

void initQ(staqueue *sq) {
    init(&(sq->s1));
    init(&(sq->s2));
}

int isQEmpty(staqueue *sq) {
    return isEmpty(&(sq->s1)) && isEmpty(&(sq->s2));
}

int isQFull(staqueue *sq) {
    return isFull(&(sq->s1));
}

void insertQ(staqueue *sq, int x) {
    if(isQFull(sq)) {
        printf("Queue is full\n");
        return;
    }
    push(&(sq->s1),x);
}

int deleteQ(staqueue *sq) {
    if(isQEmpty(sq)) {
        printf("Queue is empty\n");
        return -1;
    }
    if(!isEmpty(&(sq->s2))) return pop(&(sq->s2));
    while(!isEmpty(&(sq->s1))) push(&(sq->s2),pop(&(sq->s1)));
    return pop(&(sq->s2));
}

void displayQ(staqueue *sq) {
    if(isQEmpty(sq)) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    printf("\nThe queue is:");
    if(!isEmpty(&(sq->s2)))
        for(i=(sq->s2.top);i>=0;i--)
            printf("\n%d",sq->s2.s[i]);
    if(!isEmpty(&(sq->s1)))
        for(i=0;i<=(sq->s1.top);i++)
            printf("\n%d",sq->s1.s[i]);
    printf("\n");
}