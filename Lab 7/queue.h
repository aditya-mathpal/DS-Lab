#include<stdio.h>
#define MAX 100

typedef struct {
    int x[MAX];
    int front;
    int rear;
} queue;

void init(queue *q) {
    q->front = q->rear = -1;
}

int isFull(queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(queue *q) {
    return q->front == -1;
}

void insertq(queue *q, int x) {
    if (isFull(q))
        printf("\nOverflow\n");
    else {
        q->x[++q->rear] = x;
        if (q->front == -1) q->front = 0;
    }
}

int deleteq(queue *q) {
    int x;
    if (isEmpty(q))
        printf("\nUnderflow!!!\n");
    else if (q->front == q->rear) {
        x = q->x[q->front];
        q->front = q->rear = -1;
        return x;
    }
    else return q->x[q->front++];
}

void displayq(queue q) {
    int i;
    if (isEmpty(&q))
        printf("\nQueue is Empty!!!");
    else {
        printf("\nQueue is:\n");
        for (i = q.front; i <= q.rear; i++)
            printf("%d\n", q.x[i]);
    }
}