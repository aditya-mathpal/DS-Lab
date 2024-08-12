#include<stdio.h>
#include<string.h>

int Pal(char *s, int n) {
	int i;
	for(i=0;i<n/2;i++)
		if(*(s+i) != *(s+n-1-i)) return 0;
	return 1;
}

int main() {
	char s[100];
	printf("enter a string: ");
	fgets(s,100,stdin);
	s[strcspn(s,"\n")] = 0;
	int len;
	for(len=0;s[len]!='\0';len++);
	if(Pal(s,len)) printf("palindrome\n");
	else printf("not palindrome\n");
	return 0;
}

/*
output:
enter a string: kayak
palindrome
*/