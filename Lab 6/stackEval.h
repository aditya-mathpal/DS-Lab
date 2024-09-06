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
	return(s->top==-1)
}

int isFull(stack* s) {
	return(s->top==MAX-1)
}

void push(stack *s, int x) {
	s->s[++s->top] = x;
}

int pop(stack *s) {
	return(s->s[s->top--]);
}

int eval(char o, int a, int b) {
	switch(o) {
	case '+': return (a+b); break;
	case '-': return (a-b); break;
	case '*': return (a*b); break;
	case '/': return (a/b); break;
	case '%': return (a%b); break;
	}
}

int precedence(char o) {	//added for Q2
    if(o == '+' || o == '-') return 1;
    if(o == '*' || o == '/' || o == '%') return 2;
    return 0;
}