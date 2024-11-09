#include<stdio.h>

#define MAX 50

typedef struct {
    int s[MAX];
    int top1,top2;
}twoStack;

void init(twoStack* s) {
	s->top1 = -1;
    s->top2 = MAX;
}

int isOneEmpty(twoStack* s) {
	return(s->top1==-1);
}

int isTwoEmpty(twoStack* s) {
	return(s->top2==MAX);
}

int isFull(twoStack* s) {
	return(s->top1==s->top2-1);
}

void pushToOne(twoStack *s, int x) {
	s->s[++s->top1] = x;
}

void pushToTwo(twoStack *s, int x) {
    s->s[--s->top2] = x;
}

int popOne(twoStack *s) {
	return(s->s[s->top1--]);
}

int popTwo(twoStack *s) {
	return(s->s[s->top2++]);
}

void displayOne(twoStack *s) {
	printf("Stack 1 elements: ");
	if(isOneEmpty(s)) {
		printf("Null\n");
		return;
	}
	int i;
	for(i=s->top1;i>=0;i--) printf("%d ",s->s[i]);
	printf("\n");
}

void displayTwo(twoStack *s) {
	printf("Stack 2 elements: ");
	if(isTwoEmpty(s)) {
		printf("Null\n");
		return;
	}
	int i;
	for(i=s->top2;i<MAX;i++) printf("%d ",s->s[i]);
	printf("\n");
}