#include <bits/stdc++.h>
int main()
{
	int n;
	scanf("%d",&n);
	
	long long int dp[n+2]={0,};
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	for(int i=3; i<=n; i++)
	{
		dp[i]=(dp[i-1]+dp[i-2])%15746;
	}
	printf("%lld",dp[n]%15746);
	return 0;
}
