#include<stdio.h>
#include<stdlib.h>
void read(int** matrix, int rows, int cols) {
	int i, j;
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			scanf("%d",(*(matrix+i)+j));
}
void display(int** matrix, int rows, int cols) {
	int i, j;
	for(i=0;i<rows;i++) {
		for(j=0;j<cols;j++)
			printf("%d ",*(*(matrix+i)+j));
		printf("\n");
	}
}
void product(int** matrix1, int** matrix2, int r1, int c1, int c2) {
	int i, j, k;
	int **p;
	p = (int**) calloc(r1,c2*sizeof(int));
	for(i=0;i<r1;i++)
		p[i] = (int*) calloc(c2,sizeof(int));
	for(i=0;i<r1;i++)
		for(j=0;j<c2;j++)
			for(k=0;k<c1;k++)
				*(*(p+i)+j) += *(*(matrix1+i)+k) * *(*(matrix2+k)+j);
	printf("matrix product is:\n");
	for(i=0;i<r1;i++) {
		for(j=0;j<c2;j++)
			printf("%d ",p[i][j]);
		printf("\n");
	}
}
int main() {
	int n1, m1, n2, m2, i, k, j, l;
	int **a, **b;
	printf("enter dimensions of first matrix: ");
	scanf("%d%d",&n1,&m1);
	printf("enter dimensions of second matrix: ");
	scanf("%d%d",&n2,&m2);
	if(m1!=n2) {
		printf("incompatible matrices\n");
		return 0;
	}
	a = (int**) calloc(n1,sizeof(int*));
	for(i=0;i<n1;i++)
		a[i] = (int*) calloc(m1,sizeof(int));
	b = (int**) calloc(n2,sizeof(int*));
	for(i=0;i<n2;i++)
		b[i] = (int*) calloc(m2,sizeof(int));
	printf("enter all the elements of the first matrix row-wise: ");
	read(a,n1,m1);
	printf("enter all the elements of the second matrix row-wise: ");
	read(b,n2,m2);
	printf("first matrix is:\n");
	display(a,n1,m1);
	printf("second matrix is:\n");
	display(b,n2,m2);
	product(a,b,n1,m1,m2);
	free(a);
	free(b);
	return 0;
}