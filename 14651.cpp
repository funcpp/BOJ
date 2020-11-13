#include <stdio.h>
#include <math.h>
int n;
long long dp[33335];

int main()
{
	scanf("%d",&n);
	
	dp[1]=0;
	dp[2]=2;
	dp[3]=6;
	
	for(int i=4; i<=n; i++)
	{
		dp[i]= (dp[i-1]*3) % 1000000009;
	}
	
	printf("%d",dp[n]);
	
	return 0;
}
