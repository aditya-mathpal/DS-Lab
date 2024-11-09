#include<stdio.h>

typedef struct {
	int s[100], top;
}STACK;

void push(STACK *s, int c) {
 	s->s[++s->top] = c;
}

void display(STACK *s) {
	printf("Binary conversion: ");
	int i;
	for(i=s->top;i>=0;i--)
		printf("%d",s->s[i]);
	printf("\n");
}

int main() {
	STACK bin;
	bin.top = -1;
	printf("Enter a decimal number to convert to binary: ");
	int n;
	scanf("%d",&n);
	while(n>0) {
		push(&bin,n%2);
		n/=2;
	}
	display(&bin);
	return 0;
}

/*
output:
Enter a decimal number to convert to binary: 6
Binary conversion: 110
*/
