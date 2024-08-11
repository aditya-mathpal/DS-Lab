#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[100];
	struct {
		int day, month, year;
	}dob;
	struct {
		int houseNumber, zipCode;
		char state[100];
	}addr;
}emp;

void read(emp *e) {
	printf("enter employee name: ");
	getchar();
	fgets(e->name,100,stdin);
	e->name[strcspn(e->name,"\n")] = 0;
	printf("enter employee birthdate (day, month, year): ");
	scanf("%d%d%d",&(e->dob.day),&(e->dob.month),&(e->dob.year));
	printf("enter employee address (house number, zip code, state): ");
	scanf("%d%d%s",&(e->addr.houseNumber),&(e->addr.zipCode),e->addr.state);
}

void display(emp *e) {
	printf("name: %s, birthdate: %d/%d/%d, address: %d, %d, %s", e->name, e->dob.day, e->dob.month, e->dob.year, e->addr.houseNumber, e->addr.zipCode, e->addr.state);
}

int main() {
	printf("enter number of employees: ");
	int n, i;
	scanf("%d",&n);
	emp *e = (emp*)malloc(n*sizeof(emp));
	if(e==NULL) {
		printf("memory allocation failed\n");
		return -1;
	}
	for(i=0;i<n;i++) {
		printf("\nenter details for employee %d:\n",i+1);
		read(&e[i]);
	}
	for(i=0;i<n;i++) {
		printf("\nemployee %d:\n", i+1);
		display(&e[i]);
	}
	return 0;
	free(e);
}	
/*
output:
enter number of employees: 3

enter details for employee 1:
enter employee name: A
enter employee birthdate (day, month, year): 1 2 2005
enter employee address (house number, zip code, state): 222 576104 KA

enter details for employee 2:
enter employee name: B
enter employee birthdate (day, month, year): 2 3 2005
enter employee address (house number, zip code, state): 333 576104 KA

enter details for employee 3:
enter employee name: C
enter employee birthdate (day, month, year): 3 4 2005
enter employee address (house number, zip code, state): 444 576104 KA

employee 1:
name: A, birthdate: 1/2/2005, address: 222, 576104, KA
employee 2:
name: B, birthdate: 2/3/2005, address: 333, 576104, KA
employee 3:
name: C, birthdate: 3/4/2005, address: 444, 576104, KA
*/
