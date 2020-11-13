#include <stdio.h>
#include <string.h>
int main()
{
	int T;
	scanf("%d",&T);
	
	for(int i=0; i<T; i++)
	{
		int banbok;
		char c[20];
		
		scanf("%d %s",&banbok, c);
		for(int j=0; j<strlen(c); j++)
		{
			for(int k=0; k<banbok; k++)
			{
				printf("%c",c[j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}
