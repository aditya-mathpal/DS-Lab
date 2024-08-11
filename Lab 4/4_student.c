#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int day, year;
	int *month;
}dob;

typedef struct {
	int reg_no;
	char *name;
	char address[100];
}stu_info;

typedef struct {
	char *college_name;
	char university_name[100];
}college;

typedef struct{
	dob *d;
	stu_info s;
	college c;
}Student;

void read_student(Student *s) {
	s->d = (dob*)malloc(sizeof(dob));
	s->d->month = (int*)malloc(sizeof(int));
	s->s.name = (char*)malloc(100*sizeof(char));
	s->c.college_name = (char*)malloc(100*sizeof(char));
	printf("enter name: ");
	getchar();
    fgets(s->s.name, 100, stdin);
    s->s.name[strcspn(s->s.name, "\n")] = 0;
	printf("enter registra1tion number: ");
	scanf("%d",&(s->s.reg_no));
	printf("enter address: ");
	getchar();
    fgets(s->s.address, 100, stdin);
    s->s.address[strcspn(s->s.address, "\n")] = 0;
	printf("enter date of birth: (day, month, year)");
	scanf("%d%d%d",&(s->d->day),s->d->month,&(s->d->year));
	printf("enter college and university name: ");
	scanf("%s%s",s->c.college_name,s->c.university_name);
}

void display_student(Student *s) {
	printf("name: %s\nregistration number: %d\naddress: %s\ndate of birth: %d/%d/%d\nstudying at %s, %s\n",s->s.name, s->s.reg_no, s->s.address, s->d->day, *(s->d->month), s->d->year, s->c.college_name, s->c.university_name);
}

void free_student(Student *s) {
	free(s->d->month);
	free(s->d);
	free(s->s.name);
	free(s->c.college_name);
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
	printf("Student details:\n");
	for(i=0;i<n;i++) {
		printf("\nstudent %d:\n",i+1);
		display_student(&s[i]);
	}
	free_student(s);
	free(s);
	return 0;
}

/*
output
enter the number of students: 1
enter details for student 1:
enter name: A M     
enter registra1tion number: 2309
enter address: abc, xyz
enter date of birth: (day, month, year)1 2 2005
enter college and university name: MIT MAHE
Student details:

student 1:
name: A M
registration number: 2309
address: abc, xyz
date of birth: 1/2/2005
studying at MIT, MAHE
*/
