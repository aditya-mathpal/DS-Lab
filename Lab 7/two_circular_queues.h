#include<stdio.h>
#define N 20

typedef struct {
    int x[N];
    int front1, front2, rear1, rear2;
} dcQueue;

void initcq(dcQueue *q) {
    q->front1 = q->rear1 = -1;
    q->front2 = q->rear2 = N/2;
}

int isOneFull(dcQueue *q) {
    return ((q->rear1 + 1) % (N/2)) == q->front1;
}

int isTwoFull(dcQueue *q) {
    return ((q->rear2 + 1 - N/2) % (N/2)) == ((q->front2 - N/2) % (N/2));
}

int isOneEmpty(dcQueue *q) {
    return q->front1 == -1;
}

int isTwoEmpty(dcQueue *q) {
    return q->front2 == N/2;
}

void insertcqOne(dcQueue *q, int x) {
    if (isOneFull(q)) {
        printf("\nQueue 1 Overflow\n");
    } else {
        if (q->front1 == -1) q->front1 = 0;
        q->rear1 = (q->rear1 + 1) % (N/2);
        q->x[q->rear1] = x;
    }
}

void insertcqTwo(dcQueue *q, int x) {
    if (isTwoFull(q)) {
        printf("\nQueue 2 Overflow\n");
    } else {
        if (q->front2 == N/2) q->front2 = N/2 + 1;
        q->rear2 = N/2 + ((q->rear2 + 1 - N/2) % (N/2));
        q->x[q->rear2] = x;
    }
}

int deletecqOne(dcQueue *q) {
    int x;
    if (isOneEmpty(q)) {
        printf("\nQueue 1 Underflow!!!\n");
        return -1;
    } else {
        x = q->x[q->front1];
        if (q->front1 == q->rear1) {
            q->front1 = q->rear1 = -1;
        } else {
            q->front1 = (q->front1 + 1) % (N/2);
        }
        return x;
    }
}

int deletecqTwo(dcQueue *q) {
    int x;
    if (isTwoEmpty(q)) {
        printf("\nQueue 2 Underflow!!!\n");
        return -1;
    } else {
        x = q->x[q->front2];
        if (q->front2 == q->rear2) {
            q->front2 = q->rear2 = N/2;
        } else {
            q->front2 = N/2 + ((q->front2 + 1 - N/2) % (N/2));
        }
        return x;
    }
}

void displaycq1(dcQueue q) {
    int i;
    if (isOneEmpty(&q)) {
        printf("\nQueue 1 is Empty!!!");
    } else {
        printf("\nQueue 1 is:\n");
        i = q.front1;
        do {
            printf("%d\n", q.x[i]);
            i = (i + 1) % (N/2);
        } while (i != (q.rear1 + 1) % (N/2));
    }
}

void displaycq2(dcQueue q) {
    int i;
    if (isTwoEmpty(&q)) {
        printf("\nQueue 2 is Empty!!!");
    } else {
        printf("\nQueue 2 is:\n");
        i = q.front2;
        do {
            printf("%d\n", q.x[i]);
            i = N/2 + ((i + 1 - N/2) % (N/2));
        } while (i != (q.rear2 + 1 - N/2) % (N/2) + N/2);
    }
}