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

QUEUE merge(QUEUE x, QUEUE y) {
    QUEUE temp = (QUEUE)malloc(sizeof(struct queue));
    NODE a = x->front, b = y->front;
    init(temp);
    while(a!=NULL && b!=NULL) {
        if(a->data < b->data) {
            enqueue(temp,a->data);
            a = a->rlink;
        }
        else if(a->data > b->data) {
            enqueue(temp,b->data);
            b = b->rlink;
        }
        else {
            enqueue(temp,a->data);
            a = a->rlink;
            b = b->rlink;
        }
    }
    while(a != NULL) {
        enqueue(temp,a->data);
        a = a->rlink;
    }
    while(b != NULL) {
        enqueue(temp,b->data);
        b = b->rlink;
    }
    return temp;
}

void display(QUEUE q) {
    NODE temp = q->front;
    if(temp==NULL) {
        printf("Queue is empty.\n");
        return;
    }
    while(temp!=NULL) {
        printf("->%d",temp->data);
        temp = temp->rlink;
    }
    printf("\n");
}

int main() {
    int a, b, i;
    QUEUE A, B;
    A = (QUEUE)malloc(sizeof(struct queue));
    B = (QUEUE)malloc(sizeof(struct queue));
    init(A);
    init(B);
    scanf("%d%d",&a,&b);
    for(i=0;i<a;i++) {
        int x;
        scanf("%d",&x);
        enqueue(A,x);
    }
    for(i=0;i<b;i++) {
        int x;
        scanf("%d",&x);
        enqueue(B,x);
    }
    printf("Class A\n");
    display(A);
    printf("Class B\n");
    display(B);

    QUEUE C = (QUEUE)malloc(sizeof(struct queue));
    init(C);
    C = merge(A,B);
    printf("Joint Class\n");
    display(C);
    free(A);
    free(B);
    free(C);
    return 0;
}

/*
3 4
2 4 6
1 3 5 7
Class A
->2->4->6
Class B
->1->3->5->7
Joint Class
->1->2->3->4->5->6->7
*/