#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int stack[n]={0};
	int stacksize=0;
	for(int i=0; i<n; i++)
	{
		char c[6];
		scanf("%s",c);
		if(strcmp(c,"push")==0)
		{
			int num;
			scanf("%d",&num);
			
			stack[stacksize]=num;
			stacksize++;
		}
		else if(strcmp(c,"top")==0)
		{
			if(stacksize!=0)
				printf("%d\n",stack[stacksize-1]);
			else
				printf("-1\n");
		}
		else if(strcmp(c,"size")==0)
		{
			printf("%d\n",stacksize);
		}
		else if(strcmp(c,"empty")==0)
		{
			printf("%d\n",stacksize==0 ? 1 : 0);
		}
		else if(strcmp(c,"pop")==0)
		{
			if(stacksize!=0)
			{	
				printf("%d\n",stack[stacksize-1]);
				stack[stacksize-1]=0;
				stacksize--;
			}
			else
			{
				printf("-1\n");
			}
		}
	}
	return 0;
}
