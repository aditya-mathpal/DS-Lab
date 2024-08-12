#include<stdio.h>

int findMin(int* a, int start, int n) {
	int index = start, i;
	for(i=start+1;i<n;i++)
		if(a[i]<a[index]) index = i;
	return index;
}

void swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(int* a, int start, int n) {
	if(start>=n-1) return;
	int min = findMin(a,start,n);
	if(min!=start)
		swap(a+start,a+min);
	return(SelectionSort(a,start+1,n));
}

int main() {
	printf("enter size of array: ");
	int n, a[100], i;
	scanf("%d",&n);
	printf("enter elements of array: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	SelectionSort(a,0,n);
	printf("sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}

/*
enter size of array: 3
enter elements of array: 2 3 1
sorted array is: 1 2 3
*/