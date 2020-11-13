#include <stdio.h>

int main()
{
	char a=0xEF;
	char b=0xBF;
	char c=0xBD;
	char d=0;
	char s[] = {a,b,c,d};
	printf("%s",s);
	return 0;
}
