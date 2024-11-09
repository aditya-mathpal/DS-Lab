#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char name[100];
	int roll_no;
	float cg;
} Student;

void read_student(Student *s) {
	printf("enter name: ");
	getchar();
    fgets(s->name, 100, stdin);
    s->name[strcspn(s->name, "\n")] = 0;
	printf("enter roll number: ");
	scanf("%d",&(s->roll_no));
	printf("enter CGPA: ");
	scanf("%f",&(s->cg));
}

void display_student(Student *s) {
	printf("Student %s, roll number %d, has a CGPA of %.2f\n",s->name,s->roll_no,s->cg);
}

void sort_students(Student *s, int n) {
	int i, j;
 Student temp;
	for(i=0;i<n-1;i++) {
		for(j=0;j<n-i-1;j++) {
			if(s[j].roll_no>s[j+1].roll_no) {
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	}
}

int main() {
	int n;
	printf("enter the number of students: ");
	scanf("%d",&n);
	Student *s = (Student*)malloc(n*sizeof(Student));
	if(s==NULL) {
		printf("memory allocation failed\n");
		return -1;
	}
	int i;
	for(i=0;i<n;i++) {
		printf("enter details for student %d:\n",i+1);
		read_student(&s[i]);
	}
	sort_students(s,n);
	printf("all students roll number-wise:\n");
	for(i=0;i<n;i++)
		display_student(&s[i]);
	free(s);
	return 0;
}
/*
output:
enter the number of students: 3
enter details for student 1:
enter name: A
enter roll number: 7
enter CGPA: 8.1
enter details for student 2:
enter name: B
enter roll number: 2
enter CGPA: 8.5
enter details for student 3:
enter name: C
enter roll number: 4
enter CGPA: 9.2
all students roll number-wise:
Student B, roll number 2, has a CGPA of 8.50
Student C, roll number 4, has a CGPA of 9.20
Student A, roll number 7, has a CGPA of 8.10
*/
