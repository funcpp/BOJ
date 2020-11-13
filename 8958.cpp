#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	
	scanf("%d",&T);
	
	for(int k=0; k<T; k++)
	{
		char ox[80]={32};
		int answer=0,count=0;
		bool oi=false;
	
		scanf("%s",ox);
		for(int i=0; i<strlen(ox); i++)
		{
			if(ox[i]=='O')
			{
				count++;
				answer+=count;
			}
			else if(ox[i] == 'X')
			{
				count=0;
				oi=false;
			}
		}
		printf("%d\n",answer);
	}
	
	return 0;
}
