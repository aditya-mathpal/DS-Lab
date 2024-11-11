/*
Problem statement:
Make a circular doubly linked list to implement a queue of customers.
Menu driven program.
Functions:
insert customer to the end of the queue
move last customer to first (right circular shift) if they need immediate attention
move first customer to last (left circular shift) if their issue is resolved but a follow-up is required
display the queue
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int ID, contact;
    char name[100], issue[500];
} customer;

typedef struct node {
    customer c;
    struct node *left, *right;
} Node;

Node* getNode(customer c) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->c = c;
    temp->left = temp->right = NULL;
}

Node* insert(Node* head, customer c) {
    if(head==NULL) {
        Node* temp = getNode(c);
        temp->right = temp->left = temp;
        return temp;
    }
    Node* curr = head->left;
    Node* temp = getNode(c);
    temp->left = curr;
    temp->right = head;
    curr->right = temp;
    head->left = temp;
    return head;
}

Node* lcs(Node* head) {
    if(head==NULL) {
        printf("No customers\n");
        return NULL;
    }
    printf("%s issue is resolved, follow-up required\n",head->c.name);
    return head->right;
}

Node* rcs(Node* head) {
    if(head==NULL) {
        printf("No customers\n");
        return NULL;
    }
    printf("%s needs attention immediately\n",head->left->c.name);
    return head->left;
}

void display(Node* head) {
    if(head==NULL) {
        printf("No customers\n");
        return;
    }
    Node* curr = head;
    do {
        printf("Name: %s, ID: %d, issue: %s, contact: %d\n",curr->c.name,curr->c.ID,curr->c.issue,curr->c.contact);
        curr = curr->right;
    } while(curr!=head);
}

int main() {
    Node* head = NULL;
    printf("Enter 1 to insert, 2 for left circular shift, 3 for right circular shift, 4 to display, 5 to exit\n");
    int choice;
    while(1) {
        printf("> ");
        scanf("%d",&choice);
        getchar();
        if(choice==1) {
            customer c;
            printf("Enter name: ");
            fgets(c.name,100,stdin);
            c.name[strlen(c.name)-1] = 0; //removing newline
            printf("Enter ID: ");
            scanf("%d",&c.ID);
            getchar(); //removing newline
            printf("Enter issue: ");
            fgets(c.issue,500,stdin);
            c.issue[strlen(c.issue)-1] = 0;
            printf("Enter contact: ");
            scanf("%d",&c.contact);
            getchar();
            head = insert(head,c);
        }
        else if(choice==2) head = lcs(head);
        else if(choice==3) head = rcs(head);
        else if(choice==4) display(head);
        else if(choice==5) break;
        else printf("Enter valid input\n");
    }
    while(head!=NULL) {
        Node* temp = head->right;
        free(head);
        head = temp;
    }
    return 0;
}