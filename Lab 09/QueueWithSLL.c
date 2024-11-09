#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* rlink;
} *NODE;

typedef struct queue {
    NODE front;
    NODE rear;
} *QUEUE;

void init(QUEUE q) {
    q->front = NULL;
    q->rear = NULL;
}

NODE getNode(int x) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = x;
    temp->rlink = NULL;
    return temp;
}

void enqueue(QUEUE q, int x) {
    NODE temp = getNode(x);
    if(q->rear==NULL) q->front = temp;
    else q->rear->rlink = temp;
    q->rear = temp;
}

int dequeue(QUEUE q) {
    if(q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    int x = q->front->data;
    NODE temp = q->front;
    q->front = q->front->rlink;
    if(q->front == NULL) q->rear = NULL;
    free(temp);
    return x;
}

void display(QUEUE q) {
    NODE temp = q->front;
    if(temp==NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    while(temp!=NULL) {
        printf(" %d ",temp->data);
        temp = temp->rlink;
    }
    printf("\n");
}

int main() {
    QUEUE q = (QUEUE)malloc(sizeof(struct queue));
    int x;
    init(q);
    printf("Enter 1 to enqueue, 2 to dequeue, 3 to display, 4 to exit\n");
    do {
        printf("> ");
        scanf("%d",&x);
        if(x==1) {
            printf("Enter number to enqueue: ");
            int num;
            scanf("%d",&num);
            enqueue(q,num);
            printf("%d pushed.\n",num);
        }
        else if(x==2) {
            int temp = dequeue(q);
            if(temp!=-1) printf("%d dequeued.\n",temp);
        }
        else if(x==3) display(q);
    } while(x!=4);
    while(q->front != NULL) dequeue(q);
    free(q);
    return 0;
}

/*
output:
Enter 1 to enqueue, 2 to dequeue, 3 to display, 4 to exit
> 1
Enter number to enqueue: 5
5 pushed.
> 1
Enter number to enqueue: 6
6 pushed.
> 2
5 dequeued.
> 3
Queue contents:  6 
> 4
*/
