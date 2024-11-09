#include<stdio.h>
#include<string.h>

typedef struct {
	char s[100];
	int top;
}STACK;

void push(STACK *s, char c) {
 	s->s[++s->top] = c;
}

char pop(STACK *s) {
	return s->s[s->top--];
}

int main() {
	STACK s;
	s.top = -1;
	printf("Enter string: ");
	char str[100];
	scanf(" %s",str);
	int len = strlen(str), i;
	for(i=0;i<len/2;i++)
		push(&s,str[i]);
	if(len%2==1) i++;
	while(i<len)
		if(str[i++]!=pop(&s)) {
			printf("Not palindrome\n");
			return 0;
		}
	printf("Palindrome\n");
	return 0;
}

/*
output:
Enter string: kayak
Palindrome
*/
