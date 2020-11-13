#include <stdio.h>
#include <map>
#include <memory.h>
int p[6]={0,10000,0,25000,0,37000};
using namespace std;
map<int, bool> m;

pair<int,int> dp[110];

int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	
	for(int i=0; i<M; i++)
	{
		int t;
		scanf("%d",&t);
		m[t]=true;
	}
	
	memset(dp,1e9,sizeof(dp));
	
	for(int i=1;i<=N;i++)
	{
		if(m[i]==true)
		{
			dp[i]=min(dp[i],dp[i-1]);
		}
		dp[i+1] = dp[i+1].first<dp[i].first+p[1]?dp[i].second>=3?{dp[i].first,dp[i].second-3}:{dp[i].first+p[1],dp[i].second};
		dp[i+3] = min(dp[i+3],{dp[i].first+p[3],dp[i].second+1});
		dp[i+5] = min(dp[i+5],{dp[i].first+p[5],dp[i].second+2});
	}
	
	printf("%d",dp[N].first);
	return 0;
}
