#include <stdio.h>
#include <string.h>

int main()
{
	char c[100]={0};
	bool find=false;
	scanf("%s",c);
	for(int i=97; i<=122; i++)
	{
		for(int j=0; j<strlen(c); j++)
		{
			char d=i;
			if(d==c[j])
			{
				printf("%d ",j);
				find=true;
				break;
			}
		}
		if(!find)
			printf("-1 ");
			
		find=false;
	}
	
	return 0;
}
