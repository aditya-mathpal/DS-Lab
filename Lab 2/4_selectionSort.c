#include<stdio.h>

int findMin(int* a, int n) {
	int b=*a, i, index;
	for(i=1;i<n;i++)
		if(a[i]<b) index = i;;
	return index;
}

void swap(int a,int b) {
	int temp = a;
	a = b;
	b = temp;
}

void SelectionSort(int* a, int n) {
	static int i=0;
	if(i==n-1) return;
	int min = findMin(a,n-i);
	if(min==i) {
		i++;
		return(SelectionSort((a+1),n));
	}
	swap(a[i],a[min]);
	i++;
	return(SelectionSort((a+1),n));
}

int main() {
	printf("enter size of array: ");
	int n, a[100], i;
	scanf("%d",&n);
	printf("enter elements of array: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	SelectionSort(a,n);
	printf("sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}