#include<stdio.h>
int add(int* a, int* b) {
	return *a+*b;
}
int* product(int a, int b) {
	int* c;
	*c = a*b;
	return c;
}
int main() {
	int x,y;
	printf("enter two numbers: ");
	scanf("%d%d",&x,&y);
	printf("sum is %d\n",add(&x,&y));
	printf("product is %d\n",*product(x,y));
	int r;
	int *p;
	int **q;
	p = &r;
	q = &p;
	printf("enter value: ");
	scanf("%d",&r);
	printf("this value is stored at %p, and this address is stored at %p\n",p,q);
	return 0;
}