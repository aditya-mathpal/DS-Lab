#include<stdio.h>

void TowerOfHanoi(char source, char aux, char dest, int n) {
	if(n==1) {
	printf("move disk 1 from rod %c to rod %c\n",source,dest);
	return;
	}
	TowerOfHanoi(source,dest,aux,n-1);
	printf("move disk %d from rod %c to rod %c\n",n,source,dest);
	TowerOfHanoi(aux,source,dest,n-1);
}

int main() {
	int n;
	printf("enter number of disks: ");
	scanf("%d",&n);
	TowerOfHanoi('A','B','C',n);
	return 0;
}

/*
enter number of disks: 3
move disk 1 from rod A to rod C
move disk 2 from rod A to rod B
move disk 1 from rod C to rod B
move disk 3 from rod A to rod C
move disk 1 from rod B to rod A
move disk 2 from rod B to rod C
move disk 1 from rod A to rod C
*/