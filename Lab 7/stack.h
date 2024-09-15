#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 20

typedef struct {
	int s[MAX];
	int top;
}stack;

void init(stack* s) {
	s->top = -1;
}

int isEmpty(stack* s) {
	return(s->top==-1);
}

int isFull(stack* s) {
	return(s->top==MAX-1);
}

void push(stack *s, int x) {
	if(isFull(s)) {
		printf("Stack is full\n");
		return;
	}
	s->s[++s->top] = x;
}

int pop(stack *s) {
	if(isEmpty(s)) {
		printf("Stack is empty\n");
		return -1;
	}
	return(s->s[s->top--]);
}