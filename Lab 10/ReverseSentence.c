#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char* data;
    struct node* llink;
    struct node* rlink;
} *NODE;

NODE getNode(char* x) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = (char*)malloc(strlen(x)+1);
    strcpy(temp->data,x);
    temp->llink = temp->rlink = NULL;
    return temp;
}

NODE insertR(NODE first, char* x) {
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

void display(NODE first) {
    if(first == NULL) {
        printf("List is empty.\n");
    }
    while(first != NULL) {
        printf("%s ",first->data);
        first = first->rlink;
    }
    printf("\n");
}

NODE reverse(NODE head) {
    NODE temp = head;
    NODE newHead = NULL;
    while(temp!=NULL) {
        NODE temp2 = temp->llink;
        temp->llink = temp->rlink;
        temp->rlink = temp2;
        newHead = temp;
        temp = temp->llink;
    }
    return newHead;
}

void freeDLL(NODE head) {
    while(head != NULL) {
        NODE temp = head;
        head = head->rlink;
        free(temp->data);
        free(temp);
    }
}

int main() {
    NODE sentence = NULL;
    printf("Enter a sentence: ");
    char* s = (char*)malloc(sizeof(char)*100);
    fgets(s,100,stdin);
    s[strlen(s)-1] = 0; 
    char* word = strtok(s," ");
    while(word!=NULL) {
        sentence = insertR(sentence, word);
        word = strtok(NULL," ");
    }
    if(sentence == NULL) {
        printf("Empty sentence.\n");
        free(s);
        return 0;
    }
    sentence = reverse(sentence);
    printf("Reversed sentence is: ");
    display(sentence);
    freeDLL(sentence);
    free(s);
    return 0;
}

/*
output:
Enter a sentence: job done for food    
Reversed sentence is: food for done job
*/  