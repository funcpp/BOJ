#include <stdio.h>
#include <string.h>

int main()
{
	char c[100];
	scanf("%s",c);
	
	for(int i=0; i<strlen(c); i++)
	{
		printf("%c",c[i]);
		if((i+1)%10==0) printf("\n");
	}
	
	return 0;
}
