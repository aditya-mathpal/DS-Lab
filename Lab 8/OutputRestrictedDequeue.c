#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct {
    char **arr;
    int rear, front;
} ordq;

void init(ordq *q) {
    q->arr = (char**)malloc(MAX*sizeof(char*));
    q->rear = -1;
    q->front = -1;
}

int isEmpty(ordq *q) {
    return q->rear==-1;
}

int isFull(ordq *q) {
    return (q->rear+1)%MAX == q->front;
}

void enqueueR(ordq *q, char *x) {
    if(isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    if(isEmpty(q)) q->front = 0;
    q->rear = (q->rear+1)%MAX;
    q->arr[q->rear] = (char*)malloc((strlen(x)+1)*sizeof(char));
    strcpy(q->arr[q->rear],x);
}

void enqueueF(ordq *q, char* x) {
    if(isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    if(isEmpty(q)) q->rear=0;
    q->front = (q->front-1+MAX)%MAX;
    q->arr[q->front] = (char*)malloc((strlen(x)+1)*sizeof(char));
    strcpy(q->arr[q->front],x);
}

char* dequeue(ordq *q) {   
    if(isEmpty(q)) {
        printf("Queue is empty.\n");
        return NULL;
    }
    char* x = q->arr[q->front];
    if(q->front == q->rear) init(q);
    else q->front = (q->front+1)%MAX;
    return x;
}

void displayQueue(ordq q) {
    if(isEmpty(&q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = q.front;
    printf("Queue contents:\n");
    while(i!=q.rear) {
        printf("%s\n",q.arr[i]);
        i = (i+1)%MAX;
    }
    printf("%s\n",q.arr[q.rear]);
}
    

int main() {
    ordq *q = (ordq*)malloc(sizeof(ordq));
    init(q);
    int x;
    char s[MAX];
    printf("Enter 1 to insert rear, 2 to insert front, 3 to delete, 4 to display, 5 to exit\n");
    do {
        printf("> ");
        scanf("%d", &x);
        getchar();
        switch (x) {
        case 1:
            printf("Enter string to insert at rear: ");
            fgets(s, MAX, stdin);
            s[strcspn(s, "\n")] = 0;
            enqueueR(q, s);
            break;
        case 2:
            printf("Enter string to insert at front: ");
            fgets(s, MAX, stdin);
            s[strcspn(s, "\n")] = 0;
            enqueueF(q, s);
            break;
        case 3:
            printf("%s removed\n", dequeue(q));
            break;
        case 4:
            displayQueue(*q);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid input..\n");
        }
    } while (x != 5);

    return 0;
}


/*
Enter 1 to insert rear, 2 to insert front, 3 to delete, 4 to display, 5 to exit
> 1
Enter string to insert at rear: Hello
> 2
Enter string to insert at front: Hi
> 4   
Queue contents:
Hi
Hello
> 3
Hi removed
> 4
Queue contents:
Hello
> 5
Exiting...
*/