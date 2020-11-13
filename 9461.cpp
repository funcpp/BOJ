#include <bits/stdc++.h>
using namespace std;
long long int dp[102];
int main()
{
	int n;
	scanf("%d",&n);
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	dp[4]=2;
	dp[5]=2;
	
	for(int i=6; i<=100; i++)
	{
		dp[i]=dp[i-1]+dp[i-5];
	}
			
	int maxn=0;
	for(int i=0; i<n; i++)
	{
		int n1;
		scanf("%d",&n1);
		printf("%lld\n",dp[n1]);
	}
	return 0;
}
