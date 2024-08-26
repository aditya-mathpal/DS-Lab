#include<stdio.h>
void Forward(int* p, int size) {
	int i;
	for(i=0;i<size;i++)
		printf("%d ",*(p+i));
	printf("\n");
}
void Reverse(int* p, int size) {
	int i;
	for(i=size-1;i>=0;i--)
		printf("%d ",*(p+i));
	printf("\n");
}
int main() {
	int a[100],n,i;
	printf("enter size of array: ");
	scanf("%d",&n);
	printf("enter elements of array: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("array in forward order: ");
	Forward(a,n);
	printf("array in reverse order: ");
	Reverse(a,n);
	return 0;
}