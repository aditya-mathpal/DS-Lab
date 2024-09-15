#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct {
    char *x[MAX];
    int front, rear;
} cQueue;

void initcq(cQueue *q) {
    q->front = q->rear = -1;
}

int isFull(cQueue *q) {
    return ((q->rear + 1) % MAX == q->front);
}

int isEmpty(cQueue *q) {
    return q->front == -1;
}

void insertcq(cQueue *q, const char *str) {
    if (isFull(q)) {
        printf("\nOverflow\n");
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->x[q->rear] = (char *)malloc(strlen(str) + 1);
        if (q->x[q->rear] == NULL) {
            printf("\nMemory allocation failed\n");
            return;
        }
        strcpy(q->x[q->rear], str);
        if (q->front == -1) q->front = 0;
    }
}

char *deletecq(cQueue *q) {
    char *str;
    if (isEmpty(q)) {
        printf("\nUnderflow!!!\n");
        return NULL;
    } else {
        str = q->x[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        return str;
    }
}

void displaycq(cQueue q) {
    int i;
    if (isEmpty(&q)) {
        printf("\nQueue is Empty!!!");
    } else {
        printf("\nQueue is:\n");
        if (q.rear >= q.front) {
            for (i = q.front; i <= q.rear; i++)
                printf("%s\n", q.x[i]);
        } else {
            for (i = q.front; i < MAX; i++)
                printf("%s\n", q.x[i]);
            for (i = 0; i <= q.rear; i++)
                printf("%s\n", q.x[i]);
        }
    }
}
