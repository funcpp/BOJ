#include <stdio.h>
int floyd[25][25];
int fuck[25][25];

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			scanf("%d",&floyd[i][j]);
		}
	}
	
	for(int j=1; j<=n; j++)
	{
		for(int i=1; i<=n; i++)
		{
			if(i==j) continue;
			for(int k=1; k<=n; k++)
			{
				if(k==i || k==j) continue;
				
				if(floyd[i][k]==floyd[i][j]+floyd[j][k])
				{
					fuck[i][k]=1;
				}
				else if(floyd[i][k] > floyd[i][j] + floyd[j][k])
				{
					printf("-1");
					return 0;
				}
			}
		}
	}
	
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			ans += !fuck[i][j] * floyd[i][j];
		}
	}
	printf("%d",ans/2);
	return 0;
}
