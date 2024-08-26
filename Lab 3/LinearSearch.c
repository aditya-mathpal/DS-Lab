#include<stdio.h>
int Lsearch(int* p, int target, int size) {
	int i;
	for(i=0;i<size;i++)
		if(*(p+i)==target) return i;
	return -1;
}
int main() {
	int i,n,a[100],key;
	printf("enter size of array: ");
	scanf("%d",&n);
	printf("enter elements of the array: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter element to find: ");
	scanf("%d",&key);
	printf("element is at position %d\n",Lsearch(a,key,n)+1);
	return 0;
}