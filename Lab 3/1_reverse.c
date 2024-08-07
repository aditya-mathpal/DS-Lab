#include<stdio.h>
void Reverse(int* ptr, int size) {
    int i, temp;
    for(i=0;i<size/2;i++) {
        temp = *(ptr+i);
        *(ptr+i) = *(ptr+size-1-i);
        *(ptr+size-1-i) = temp;
    }
}
int main() {
    int a[100], n;
    printf("enter size of array: ");
    scanf("%d", &n);
    printf("input elements of the array: ");
    int i;
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    Reverse(a,n);
    printf("reversed array is: ");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    return 0;
}