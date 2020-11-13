#include <stdio.h>
#define min(a,b) a<b?a:b

int floyd[405][405];
int main()
{
	int V,E;
	scanf("%d %d",&V,&E);
	for(int i=1; i<=V; i++)
	{
		for(int j=1; j<=V; j++)
		{
			if(i==j) continue;
			floyd[i][j]=987654321;
		}
	}
	
	for(int i=0; i<E; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		floyd[a][b]=c;
	}
	
	for(int j=1; j<=V; j++)
	{
		for(int i=1; i<=V; i++)
		{
			for(int k=1; k<=V; k++)
			{
				floyd[i][k] = min(floyd[i][k],floyd[i][j]+floyd[j][k]);
			}
		}
	}
	
	int ans=987654321;
	for(int i=1; i<=V; i++)
	{
		for(int j=1; j<=V; j++)
		{
			if(i==j) continue;
			ans = min(ans, floyd[i][j] + floyd[j][i]);
		}
	}
	printf("%d",ans == 987654321 ? -1 : ans);
	return 0;
}
