#include "stack.h"

int main() {
    stack opnd,in;
	char x, out[20];
	int i,j=0;
    init(&in);
    init(&opnd);
	printf("enter a prefix expression (only single digit operands): ");
    while((x = getchar()) != '\n') push(&in,x);
    while(!isEmpty(&in)) {
        if(isdigit(x=pop(&in))) push(&opnd,x);
        //need to fix this else block
        else {
            out[j++] = pop(&opnd);
            out[j++] = pop(&opnd);
            out[j++] = x;
            push(&opnd,'#');
        }
    }
    out[j] = '\0';
    printf("The postfix expression is: ");
    for(i=0;i<j;i++)
        if(out[i]!='#') printf("%c",out[i]);
    return 0;
}

/*
output:
enter a prefix expression (only single digit operands): +1*32
The postfix expression is: 32*1+
*/