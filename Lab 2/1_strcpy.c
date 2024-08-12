#include<stdio.h>

void copy(char *source, char *output) {
	if(*source == '\0') return;
	else *output = *source;
	return copy(source+1,output+1);
}

int main() {
	char s[100], d[100];
	printf("enter a string: ");
	fgets(s,100,stdin);
	copy(s,d);
	printf("the string was copied to %p\nthe string is: ",d);
	puts(d);
	return 0;
}

/*
output:
enter a string: test code
the string was copied to 0x7ffecd903a90
the string is: test code
*/