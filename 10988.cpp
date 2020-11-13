#include <stdio.h>
#include <string.h>

int main()
{
	char c[101];
	scanf("%s",c);
	
	int len = strlen(c);
	for(int i=0; i<len/2; i++)
	{
		if(c[i]!=c[len-i-1])
		{
			printf("0");
			return 0;
		}
	}
	printf("1");
	return 0;
}
