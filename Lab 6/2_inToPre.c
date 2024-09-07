#include "stack.h"

int main() {
    stack opnd,opr,in;
	char x;
	int i;
    init(&in);
    init(&opnd);
    init(&opr);
	printf("enter an infix expression (only single digit operands): ");
    while((x = getchar()) != '\n') push(&in,x);
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

/*
output:
enter an infix expression (only single digit operands): 3*2+1
The prefix expression is: +*321
*/