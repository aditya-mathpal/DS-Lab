#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int real, img;
}complex;
void add(int r1,int i1,int r2,int i2) {
	printf("%d+(%di) + %d+(%di) = %d+(%di)\n",r1,i1,r2,i2,r1+r2,i1+i2);
}
void multiply(int r1,int i1,int r2,int i2) {
	printf("[%d+(%di)] x [%d+(%di)] = %d+(%di)\n",r1,i1,r2,i2,r1*r2-i1*i2,r1*i2+r2*i1);
}
void subtract(int r1,int i1,int r2,int i2) {
	printf("[%d+(%di)] - [%d+(%di)] = %d+(%di)\n",r1,i1,r2,i2,r1-r2,i1-i2);
}
int main() {
	int operation;
	complex a,b;
	printf("enter first complex number: ");
	scanf("%d%d",&a.real,&a.img);
	printf("enter second complex number: ");
	scanf("%d%d",&b.real,&b.img);
	printf("enter operation (1 for addition, 2 for multiplication, 3 for subtraction): ");
	scanf("%d",&operation);
	switch(operation) {
	case(1):
		add(a.real,a.img,b.real,b.img);
		break;
	case(2):
		multiply(a.real,a.img,b.real,b.img);
		break;
	case(3):
		subtract(a.real,a.img,b.real,b.img);
		break;
	}
	return 0;
}