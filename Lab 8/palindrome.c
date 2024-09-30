#include<stdio.h>
#include<string.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int front, rear;
} dequeue;

void init(dequeue *dq) {
    dq->front = dq->rear = -1;
}

int isEmpty(dequeue *dq) {
    return dq->front==-1 && dq->rear==-1;
}

int isFull(dequeue *dq) {
    return (dq->rear+1)%MAX == dq->front;
}

void enqueueR(dequeue *dq, char x) {
    if(isFull(dq)) {
        printf("Error: String Too Large\n");
        return;
    }
    if(isEmpty(dq)) dq->front++;
    dq->rear = (dq->rear+1)%MAX;
    dq->arr[dq->rear] = x;
}

void enqueueF(dequeue *dq, char x) {
    if(isFull(dq)) {
        printf("Error: String Too Large\n");
        return;
    }
    if(isEmpty(dq)) {
        dq->rear = dq->front = 0;
    }
    else dq->front = (dq->front-1+MAX)%MAX;
    dq->arr[dq->front] = x;
}

char dequeueF(dequeue *dq) {
    char x = dq->arr[dq->front];
    if(dq->front==dq->rear) init(dq);
    else dq->front = (dq->front+1)%MAX;
    return x;
}

char dequeueR(dequeue *dq) {
    char x = dq->arr[dq->rear];
    if(dq->front==dq->rear) init(dq);
    else dq->rear = (dq->rear-1+MAX)%MAX;
    return x;
}

int palindrome(dequeue *dq) {
    while(dq->front != dq->rear)
        if(dequeueF(dq) != dequeueR(dq)) return 0;
    return 1;
}

int main() {
    dequeue dq;
    init(&dq);
    char s[MAX];
    printf("Enter a string: ");
    fgets(s,MAX,stdin);
    int i;
    for(i=0;s[i]!='\n';i++) enqueueR(&dq,s[i]);
    if(palindrome(&dq)) printf("Palindrome\n");
    else printf("Not Palindrome\n");
    return 0;
}

/*
output:
Enter a string: kayak
Palindrome
*/
