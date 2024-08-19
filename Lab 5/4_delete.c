#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int s[100], top;
}STACK;

void push(STACK *s, int a) {
 	s->s[++s->top] = a;
}

int pop(STACK *s) {
	return s->s[s->top--];
}

int main() {
	STACK s;
	s.top = -1;
	int n, k, i, x=0;
	printf("Enter number of elements of array: ");
	scanf("%d",&n);
	int* arr = (int*)calloc(n,sizeof(int));
	printf("Enter elements of the array: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter number of elements to delete: ");
	scanf("%d",&k);
	while(k--) {
		int flag=1;
		for(i=0;i<n-x+1;i++) {
			if(arr[i]<arr[i+1] && flag == 1) {
				x++;
				flag = 0;
				continue;
			}
			push(&s,arr[i]);
		}
		for(i=n-x-1;i>=0;i--)
			arr[i] = pop(&s);
	}
	for(i=0;i<n-x;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}

/*
output:
Enter number of elements of array: 5
Enter elements of the array: 75 6 8 7 10
Enter number of elements to delete: 2
75 8 10
*/