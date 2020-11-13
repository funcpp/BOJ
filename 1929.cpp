#include <stdio.h>
int npn[1000005];

int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	
	npn[1]=1;
	
	for(int i=2; i<=n; i++)
	{
		for(int j=2; i*j<=n; j++)
		{
			npn[i*j]=1;
		}
	}
	
	
	for(int i=m; i<=n; i++)
	{
		if(!npn[i])
		{
			printf("%d\n",i);
		}
	}
	return 0;
}
