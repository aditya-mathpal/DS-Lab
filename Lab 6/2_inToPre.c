#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include "stackEval.h"

int main() {
    stack opnd,opr,in;
	char exp[100],x,c;
	int i;
    init(&in);
    init(&opnd);
    init(&opr);
	printf("enter an infix expression (only single digit operands): ");
    while((c = getchar()) != '\n') {
        push(&in,c);
    }
    while(!isEmpty(&in)) {
        if(isdigit(x=pop(&in))) push(&opnd,x);
        else if(isEmpty(&opr) || precedence(x) > precedence(opr.s[opr.top])) push(&opr,x);
        else {
            push(&opnd,pop(&opr));
            push(&opr,x);
        }
    }
    while(!isEmpty(&opr)) push(&opnd,pop(&opr));
    printf("The prefix expression is: ");
    while(!isEmpty(&opnd)) printf("%c",pop(&opnd));
    return 0;
}