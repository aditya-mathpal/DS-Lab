#include<stdio.h>
#include<string.h>

int Pal(char *s, int n, int *i) {
	if(*i == n/2) return 1;
	if(*(s+*i) != *(s+n-1-*i)) return 0;
	(*i)++;
	return Pal(s,n,i);
}

int main() {
	int *i;
	*i = 0;
	char s[100];
	printf("enter a string: ");
	fgets(s,100,stdin);
	s[strcspn(s,"\n")] = 0;
	int len=strlen(s);
	if(Pal(s,len,i)) printf("palindrome\n");
	else printf("not palindrome\n");
	return 0;
}

/*
output:
enter a string: kayak
palindrome
*/