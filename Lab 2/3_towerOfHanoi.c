#include<stdio.h>

void TowerOfHanoi(char source, char aux, char dest, int n, int* i) {
	if(n==1) {
	printf("move disk 1 from rod %c to rod %c\n",source,dest);
	(*i)++;
	return;
	}
	TowerOfHanoi(source,dest,aux,n-1,i);
	printf("move disk %d from rod %c to rod %c\n",n,source,dest);
	(*i)++;
	TowerOfHanoi(aux,source,dest,n-1,i);
}

int main() {
	int *i;
	int n;
	*i = 0;
	printf("enter number of disks: ");
	scanf("%d",&n);
	TowerOfHanoi('A','B','C',n,i);
	printf("%d moves\n",*i);
	return 0;
}

/*
output:
enter number of disks: 3
move disk 1 from rod A to rod C
move disk 2 from rod A to rod B
move disk 1 from rod C to rod B
move disk 3 from rod A to rod C
move disk 1 from rod B to rod A
move disk 2 from rod B to rod C
move disk 1 from rod A to rod C
7 moves
*/