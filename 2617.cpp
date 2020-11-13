#include <stdio.h>
int N,M;

int floyd[105][105];

int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0; i<M; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		floyd[a][b]=1;
		floyd[b][a]=-1;
	}
	
	for(int j=1; j<=N; j++)
	{
		for(int i=1; i<=N; i++)
		{
			for(int k=1; k<=N; k++)
			{
				if(floyd[i][j]==1 && floyd[j][k]==1) floyd[i][k]=1;
				if(floyd[i][j]==-1 && floyd[j][k]==-1) floyd[i][k]=-1;
			}
		}
	}
	
	int cut = N/2+1;
	int ans=0;
	for(int i=1; i<=N; i++)
	{
		int cnt=0, cnt1=0;
		for(int j=1; j<=N; j++)
		{
			if(floyd[i][j]==1) cnt++;
			if(floyd[i][j]==-1) cnt1++;
		}
		if(cnt>=cut || cnt1>=cut) ans++;
	}
	printf("%d",ans);
	
	return 0;
}
