#include<stdio.h>
#include<stdlib.h>
int Smallest(int* a, int n) {
	int i, small = a[i];
	for(i=1;i<n;i++)
		if(a[i]<small)
			small = a[i];
	return small;
}
int main() {
	int* ptr;
	int i, n;
	printf("enter number of elements: ");
	scanf("%d",&n);
	ptr = (int*) calloc(n,sizeof(int));
	printf("enter the elements of the array: ");
	for(i=0;i<n;i++)
		scanf("%d",ptr+i);
	printf("the smallest element is %d\n",Smallest(ptr,n));
	free(ptr);
	return 0;
}