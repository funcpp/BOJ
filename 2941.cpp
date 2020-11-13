#include <stdio.h>
#include <string.h>

int main()
{
	char c[101]={};
	scanf("%s",c);
	int len = strlen(c);
	int count=0;
	for(int i=0; i<len; i++)
	{
		if(*(c+i)=='c' && i!=len-1)
		{
			if(*(c+i+1)=='=' || *(c+i+1)=='-')
			{
				i++;
			}
		}
		else if(*(c+i)=='d')
		{
			if(*(c+1+i)=='z'&&*(c+i+2)=='=')
			{
				i++;
				i++;
			}
			else if(*(c+1+i)=='-')
			{
				i++;
			}
		}
		else if(*(c+i) == 'l' || *(c+i)=='n')
		{
			if(*(c+1+i)=='j')
				i++;
		}
		else if(*(c+i)=='s' || *(c+i)=='z')
		{
			if(*(c+i+1)=='=')
			{	
				i++;
			}
		}
		count++;
	}
	printf("%d\n",count);
	return 0;
}
