#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* llink;
    struct node* rlink;
} *NODE;

NODE getNode(int x) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = x;
    temp->llink = temp->rlink = NULL;
    return temp;
}

NODE insertF(NODE first, int x) {
    if(first == NULL) {
        return getNode(x);
    }
    NODE temp = getNode(x);
    first->llink = temp;
    temp->rlink = first;
    return temp;
}

NODE insertR(NODE first, int x) {
    if(first == NULL) {
        return getNode(x);
    }
    NODE temp1 = first;
    while(temp1->rlink != NULL) temp1 = temp1->rlink;
    NODE temp2 = getNode(x);
    temp1->rlink = temp2;
    temp2->llink = temp1;
    return first;
}

NODE deleteF(NODE first) {
    if(first==NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    printf("%d deleted.\n",first->data);
    if(first->rlink==NULL) return NULL;
    first = first->rlink;
    first->llink = NULL;
    return first;
}

NODE deleteR(NODE first) {
    if(first==NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if(first->rlink==NULL) {
        printf("%d deleted.\n",first->data);
        return NULL;
    }
    NODE temp = first;
    while(temp->rlink->rlink != NULL) temp = temp->rlink;
    printf("%d deleted.\n",temp->rlink->data);
    temp->rlink = NULL;
    return first;
}

void display(NODE first) {
    if(first == NULL) {
        printf("List is empty.\n");
    }
    while(first != NULL) {
        printf("->%d",first->data);
        first = first->rlink;
    }
    printf("\n");
}

int main() {
    NODE list = NULL;
    int x;
    printf("Enter 1 to insert in the front, 2 to insert at the end, 3 to delete in the front, 4 to delete at the end, 5 to display, and 6 to exit.\n");
    do {
        printf("> ");
        scanf("%d",&x);
        if(x==1 || x==2) {
            printf("Enter element to insert: ");
            int e;
            scanf("%d",&e);
            if(x==1) list = insertF(list,e);
            else list = insertR(list,e);
        }
        else if(x==3) list = deleteF(list);
        else if(x==4) list = deleteR(list);
        else if(x==5) display(list);
        else if(x!=6) printf("Please enter a valid input.\n");
    }
    while(x!=6);
    printf("Exiting.\n");
    return 0;
}

/*
output:
Enter 1 to insert in the front, 2 to insert at the end, 3 to delete in the front, 4 to delete at the end, 5 to display, and 6 to exit.
> 1
Enter element to insert: 2
> 1
Enter element to insert: 1
> 2
Enter element to insert: 3
> 5
->1->2->3
> 3
1 deleted.
> 4
3 deleted.
> 5
->2
> 6
Exiting.
*/