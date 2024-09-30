#include<stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX], front, rear;
}queue;

void init(queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(queue *q) {
    return q->front == -1 && q->rear == -1;
}

int isFull(queue *q) {
    return (q->rear+1)%MAX == q->front;
}

void enqueue(queue *q, int x) {
    if(isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    if(isEmpty(q)) q->front++;
    q->rear = (q->rear+1)%MAX;
    q->arr[q->rear] = x;
}

int dequeue(queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int x = q->arr[q->front];
    if(q->front == q->rear) init(q);
    else q->front = (q->front+1)%MAX;
    return x;
}

void display(queue q) {
    if(isEmpty(&q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i;
    if(q.rear>=q.front)
        for(i=q.front;i<=q.rear;i++) printf(" %d ",q.arr[i]);
    else {
        for (i=q.front;i<MAX;i++) printf(" %d ", q.arr[i]);
        for (i=0;i<=q.rear;i++) printf(" %d ", q.arr[i]);
    }
    printf("\n");
}

void reverse(queue *q) {
    int arr[MAX],count;
    for(count=0;!isEmpty(q);count++) arr[count] = dequeue(q);
    while(count--) enqueue(q,arr[count]);
}

int main() {
    queue q;
    init(&q);
    int n,x;
    printf("Enter size of queue: ");
    scanf("%d",&n);
    printf("Enter elements of queue: ");
    while(n--) {
        scanf("%d",&x);
        enqueue(&q,x);
    }
    printf("Your Queue: ");
    display(q);
    reverse(&q);
    printf("Reversed Queue: ");
    display(q);
    return 0;
}

/*
output:
Enter size of queue: 5
Enter elements of queue: 1 2 3 4 5
Your Queue:  1  2  3  4  5 
Reversed Queue:  5  4  3  2  1
*/
            
