#include<stdio.h>
int main() {
    int a[100], b[3], n, i, j, k;
    printf("enter number of elements in the array: ");
    scanf("%d",&n);
    printf("enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("the triplets that sum to zero are:\n");
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            for(k=j+1;k<n;k++) {
                if(a[i]+a[j]+a[k]==0)
                    printf("%d %d %d\n",a[i],a[j],a[k]);
            }
        }
    }
    return 0;
}