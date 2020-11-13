#include <stdio.h>
#include <memory.h>
#define min(a,b) a<b?a:b;

int line[105][105];
int main()
{
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0; i<m; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(!line[a][b]) line[a][b]=c;
		else line[a][b]=min(line[a][b],c);
	}
	
	for(int j=1; j<=n; j++)
	{
		for(int i=1; i<=n; i++)
		{
			if(!line[i][j]) continue;
			for(int k=1; k<=n; k++)
			{
				if(!line[j][k]) continue;
				if(i==k) continue;
				
				if(!line[i][k]) line[i][k]=line[i][j]+line[j][k];
				else line[i][k]=min(line[i][k],line[i][j]+line[j][k]);
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			printf("%d ",line[i][j]);
		}
		printf("\n");
	}
	return 0;
}
