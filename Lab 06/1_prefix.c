#include "stack.h"

int main() {
	stack s;
	char c,exp[100];
	int x,y,z,i;
	init(&s);
	printf("enter a prefix expression (only single digit operands): ");
	scanf("%s",exp);
	int len = strlen(exp);
	for(i=len-1;i>=0;i--) {
		if(isdigit(c=exp[i])) push(&s,c-'0');
		else {
			x = pop(&s);
			y = pop(&s);
			z = eval(c,x,y);
			push(&s,z);
		}
	}
	printf("Result is %d\n",pop(&s));
	return 0;
}

/*
enter a prefix expression (only single digit operands): +*321
Result is 7
*/