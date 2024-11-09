#include<stdio.h>
int Palindrome(char* p) {
	int len;
	for(len=0;*(p+len)!='\0';len++);
	int i;
	for(i=0;i<len/2;i++) {
		if(*(p+i)!=*(p+len-1-i))
			return 0;
	}
	return 1;
}

int main() {
	char s[100];
	printf("enter string: ");
	gets(s);
	if(Palindrome(s)) printf("palindrome\n");
	else printf("not palindrome\n");
	return 0;
}