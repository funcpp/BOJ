#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
	int n;
	scanf("%d",&n);
	int dp[n+1]={0,}, wine[n+1]={0,};
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&wine[i]);
	}
	dp[1]=wine[1];
	if(n!=1)
	{
		dp[2]=wine[1]+wine[2];
	}
	
	for(int i=3; i<=n; i++)
	{
		dp[i]=max(dp[i-1],max(dp[i-2]+wine[i],dp[i-3]+wine[i-1]+wine[i]));
	}
	printf("%d",dp[n]);
	return 0;
}
