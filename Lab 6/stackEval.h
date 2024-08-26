#define MAX 20

typedef struct stack {
	int s[MAX];
	int top;
}stack;

void init(stack* s) {
	s->top = -1;
}

int isEmpty(stack* s) {
	if(s->top==-1)
		return 1;
	return 0;
}

int isFull(stack* s) {
	if(s->top==MAX-1)
		return 1;
	return 0;
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