#include <stdio.h>
#define max(a, b) (((a)>(b))?(a):(b))
#define DAYS 100005
 
int v[15][DAYS];
int dp[DAYS][15];
int dp2[DAYS];

int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d",&v[i][j]);
		}
	}
	
	int pidx=0;
	
	for(int i=0; i<m; i++)
	{
		dp[0][i] = v[i][0];
		if(dp2[0] < dp[0][i])
		{
			pidx = i;
			dp2[0] = dp[0][i];
		}
	}
	
	printf("\n");
	printf("%d ",pidx);
	//printf("%d ",dp2[0]);
	
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			dp[i][j] = (j==pidx) ? dp2[i-1]+v[j][i]/2 : dp2[i-1]+v[j][i];
			if(dp2[i]<dp[i][j])
			{
				pidx = j;
				dp2[i] = dp[i][j];
			}
			//printf("%d %d\n",j,pidx);
			//printf("%d %d %d\n",dp2[i-1],v[j][i-1],dp2[i]);
		}
		printf("%d ",pidx);
		//printf("%d ",dp2[i]);
	}
	
	printf("%d",dp2[n-1]);
	
	return 0;
}

