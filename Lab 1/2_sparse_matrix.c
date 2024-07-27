#include<stdio.h>
int sparse(float zeros, int row, int col) {
    if(zeros/(row*col)>=0.5) return 1;
    else return 0;
}
int main() {
    int i, j, a[100][100], n, m;
    float z=0;
    printf("enter number of rows and columns in the matrix: ");
    scanf("%d%d",&n,&m);
    printf("enter all the elements of the matrix row-wise: ");
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
                z++;
        }
    }
    printf("the matrix input is:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }
    if(sparse(z,n,m)) printf("matrix is sparse\n");
    else printf("matrix is not sparse\n");
    return 0;
}