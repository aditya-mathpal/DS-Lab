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
    printf("Contents: ");
    while(temp!=NULL) {
        printf(" %d ",temp->data);
        temp = temp->rlink;
    }
    printf("\n");
}

NODE setUnion(NODE head1, NODE head2) {
    NODE result = NULL, ptr1 = head1, ptr2 = head2;
    while(ptr1!=NULL && ptr2!=NULL) {
        if(ptr1->data < ptr2->data) {
            result = insert(result,ptr1->data);
            ptr1 = ptr1->rlink;
        }
        else if(ptr1->data > ptr2->data) {
            result = insert(result,ptr2->data);
            ptr2 = ptr2->rlink;
        }
        else {
            result = insert(result,ptr1->data);
            ptr1 = ptr1->rlink;
            ptr2 = ptr2->rlink;
        }
    }
    while(ptr1!=NULL) {
        result = insert(result,ptr1->data);
        ptr1 = ptr1->rlink;
    }
    while(ptr2!=NULL) {
        result = insert(result,ptr2->data);
        ptr2 = ptr2->rlink;
    }
    return result;
}

NODE setIntersection(NODE head1, NODE head2) {
    NODE result = NULL, ptr1 = head1, ptr2 = head2;
    while(ptr1!=NULL && ptr2!=NULL) {
        if(ptr1->data == ptr2->data) {
            result = insert(result,ptr1->data);
            ptr1 = ptr1->rlink;
            ptr2 = ptr2->rlink;
        }
        else if(ptr1->data < ptr2->data) ptr1 = ptr1->rlink;
        else ptr2 = ptr2->rlink;
    }
    return result;
}

void freeList(NODE head) {
    NODE temp;
    while (head != NULL) {
        temp = head;
        head = head->rlink;
        free(temp);
    }
}

int main() {
    NODE a = NULL;
    NODE b = NULL;

    a = insert(a, 1);
    a = insert(a, 3);
    a = insert(a, 5);

    b = insert(b, 2);
    b = insert(b, 3);
    b = insert(b, 4);

    printf("List 1 ");
    display(a);
    printf("List 2 ");
    display(b);

    NODE unionResult = setUnion(a, b);
    printf("Union ");
    display(unionResult);

    NODE intersectionResult = setIntersection(a, b);
    printf("Intersection ");
    display(intersectionResult);

    freeList(a);
    freeList(b);
    freeList(unionResult);
    freeList(intersectionResult);

    return 0;
}

/*
List 1 Contents:  1  3  5 
List 2 Contents:  2  3  4 
Union Contents:  1  2  3  4  5 
Intersection Contents:  3
*/