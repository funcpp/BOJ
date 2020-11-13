#include <stdio.h>
int floyd[505][505];

int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	
	for(int i=0; i<M; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		floyd[a][b]=-1;
		floyd[a][b]=1;
	}
	
	for(int j=1; j<=N; j++)
	{
		for(int i=1; i<=N; i++)
		{
			for(int k=1; k<=N; k++)
			{
				if(!floyd[i][k])
				{
					if(floyd[i][j]==1 && floyd[j][k]==1) floyd[i][k]=1;
					else if(floyd[i][j]==-1 && floyd[j][k]==-1) floyd[i][k]=-1;
				}
			}
		}
	}
	
	int ans=0;
	for(int i=1; i<=N; i++)
	{
		bool b=true;
		for(int j=1; j<=N; j++)
		{
			if(i==j) continue;
			
			if(!floyd[i][j] && !floyd[j][i])
			{
				b=false;
				break;
			}
		}
		if(b) ans++;
	}
	printf("%d",ans);
	
	return 0;	
}
