#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int card[n+5];
	for(int i=1; i<=n; i++)
		scanf("%d",card+i);
		
	int dp[n+5]={0,};
	dp[1]=card[1];
	
	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<=i; j++) //i-j개 최대가격 + j개 가격 
		{
			dp[i]=dp[i]<dp[i-j]+card[j]?dp[i-j]+card[j]:dp[i]; 
		}
	}
	
	printf("%d",dp[n]);
	
	return 0;
}
