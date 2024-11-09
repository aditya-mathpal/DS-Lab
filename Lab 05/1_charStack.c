#include<stdio.h>

typedef struct {
	char s[10];
	int top;
}STACK;

int isEmpty(STACK *s) {
	if(s->top<0) return 1;
	else return 0;
}

int isFull(STACK *s) {
	if(s->top>=9) return 1;
	else return 0;
}

void push(STACK *s, char c) {
	if(isFull(s)) {
		printf("Stack is full.\n");
		return;
	}
 	s->s[++s->top] = c;
}

void pop(STACK *s) {
	if(isEmpty(s)) {
		printf("Stack is empty.\n");
		return;
	}
	printf("Popped element: %c\n",s->s[s->top--]);
}

void display(STACK *s) {
	printf("Stack elements: ");
	if(isEmpty(s)) {
		printf("Null\n");
		return;
	}
	int i;
	for(i=s->top;i>=0;i--)
		printf("%c ",s->s[i]);
	printf("\n");
}



int main() {
	STACK s;
	s.top = -1;
	while(1) {
		printf("Stack operations: enter 1 to push, 2 to pop, 3 to display: ");
		int n;
		scanf("%d",&n);
		switch(n) {
			case 1:
				printf("Enter character to push: ");
				char c;
				scanf(" %c",&c);
				push(&s,c);
				break;
			case 2:
				pop(&s);
				break;
			case 3:
				display(&s);
				break;
		}
	}
	return 0;
}

/*
output:
Stack operations: enter 1 to push, 2 to pop, 3 to display: 1
Enter character to push: 5
Stack operations: enter 1 to push, 2 to pop, 3 to display: 3
Stack elements: 5 
Stack operations: enter 1 to push, 2 to pop, 3 to display: 2
Popped element: 5
*/
