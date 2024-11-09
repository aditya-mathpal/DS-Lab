#include<stdio.h>
int Lsearch(int* array, int size, int target) {
    int i;
    for(i=0;i<size;i++) {
        if(array[i]==target)
            return i+1;
    }
    return -1;
}
int main() {
    int a[100], i, n, key;
    printf("enter size of array: ");
    scanf("%d",&n);
    printf("enter elements of the array: ");
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    printf("entered array is: ");
    for(i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
    printf("\nenter the integer to be searched: ");
    scanf("%d",&key);
    int pos = Lsearch(a,n,key);
    printf("the element is located at position %d",pos);
    return 0;
}