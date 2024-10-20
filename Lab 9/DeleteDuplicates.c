#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* rlink;
} *NODE;

NODE getNode(int x) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = x;
    temp->rlink = NULL;
    return temp;
}

NODE insert(NODE head, int x) {
    if(head==NULL) head = getNode(x);
    else {
        NODE temp = head;
        while(temp->rlink != NULL) temp = temp->rlink;
        temp->rlink = getNode(x);
    }
    return head;
}

void display(NODE head) {
    if(head==NULL) {
        printf("List is empty.\n");
        return;
    }
    NODE temp = head;
    while(temp!=NULL) {
        printf(" %d ",temp->data);
        temp = temp->rlink;
    }
    printf("\n");
}

void deleteDuplicates(NODE head) {
    while(head != NULL && head->rlink != NULL) {
        if(head->data == head->rlink->data) {
            NODE temp = head->rlink;
            head->rlink = temp->rlink;
            free(temp);
        }
        else head = head->rlink;
    }
}

int main() {
    NODE list = NULL;
    printf("Enter number of elements in the list: ");
    int n, x;
    scanf("%d",&n);
    printf("Enter elements of the list in ascending order: ");
    while(n--) {
        scanf("%d",&x);
        list = insert(list, x);
    }
    printf("Initial list: ");
    display(list);

    deleteDuplicates(list);
    printf("Updated list: ");
    display(list);
    return 0;
}

/*
output:
Enter number of elements in the list: 4
Enter elements of the list in ascending order: 1 2 2 3
Initial list:  1  2  2  3
Updated list:  1  2  3
*/