#include <stdio.h>
#define min(a,b) a<b?a:b;
#define fuck 987654321

int floyd[1005][1005];

int main()
{
	int N,M,X;
	scanf("%d %d %d",&N,&M,&X);
	
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			if(i!=j) floyd[i][j]=987654321;
		}
	}
	
	for(int i=0; i<M; i++)
	{
		int a,b,t;
		scanf("%d %d %d",&a,&b,&t);
		floyd[a][b] = min(floyd[a][b],t);
	}
	
	for(int j=1; j<=N; j++)
	{
		for(int i=1; i<=N; i++)
		{	
			for(int k=1; k<=N; k++)
			{	
				floyd[i][k] = floyd[i][j]+floyd[j][k] < floyd[i][k] ? floyd[i][j]+floyd[j][k] : floyd[i][k];
			}
		}
	}
	
	int max=0;
	for(int i=1; i<=N; i++)
	{
		max = max < floyd[i][X]+floyd[X][i] ? floyd[i][X]+floyd[X][i] : max;
	}
	printf("%d",max);
	return 0;
}
