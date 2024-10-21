#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* llink;
	struct node* rlink;
} *NODE;

typedef struct header {
	NODE llink, rlink;
} *HEAD;

HEAD getHead() {
	HEAD header = (HEAD)malloc(sizeof(HEAD));
	header->llink = header->rlink = header;
	return header;
} 

NODE getNode(int x) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = x;
    temp->llink = temp->rlink = NULL;
    return temp;
}

HEAD insertR(HEAD header, int x) {
	NODE temp = getNode(x);
	if(header->rlink==header) {
		header->rlink = temp;
		header->llink = temp;
		temp->rlink = header;
		temp->llink = header;
	}
	else {
        NODE last = header->llink;
        last->rlink = temp;
        temp->llink = last;
        temp->rlink = header;
        header->llink = temp;
    }
	return header;
}

HEAD add(HEAD a, HEAD b) {
	NODE nodeA = a->rlink, nodeB = b->rlink;
	HEAD c = getHead();
	int carry=0, sum;
	while (nodeA!=a || nodeB!=b || carry) {
        sum = carry;
        if (nodeA!=a) {
            sum += nodeA->data;
            nodeA = nodeA->rlink;
        }
        if (nodeB!=b) {
            sum += nodeB->data;
            nodeB = nodeB->rlink;
        }
        carry = sum/10;
        insertR(c,sum%10);
    }
	return c;
}

void displayReversed(NODE x) {
	if(x == NULL || x == x->rlink) return;
	displayReversed(x->rlink);
	printf("->%d",x->data);
}

int main() {
	HEAD list1 = getHead(), list2 = getHead();
	int num1, num2;
	printf("Enter two positive integers: ");
	scanf("%d%d",&num1,&num2);
	while(num1) {
		list1 = insertR(list1,num1%10);
		num1/=10;
	}
	while(num2) {
		list2 = insertR(list2,num2%10);
		num2/=10;
	}
	HEAD sum = add(list1,list2);
	displayReversed(sum->rlink);
	return 0;
}