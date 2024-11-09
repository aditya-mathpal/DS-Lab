#include<stdio.h>
int Bsearch(int* p,int target,int size) {
	int i,min=0,max=size-1,mid;
	while(max>=min) {
		mid = (min+max)/2;
		if(*(p+mid)==target) return mid;
		else if(*(p+mid)>target) max = mid-1;
		else min = mid+1;
	}
	return -1;
}
int main() {
	int i,n,a[100],key;
	printf("enter size of array: ");
	scanf("%d",&n);
	printf("enter elements of the array (in ascending order): ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter element to find: ");
	scanf("%d",&key);
	printf("element is at position %d\n",Bsearch(a,key,n)+1);
	return 0;
}