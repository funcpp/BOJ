#include <stdio.h>

struct Work
{
	int days, money;	
};

int main()
{
	int n;
	scanf("%d",&n);
	
	Work work[n+5]={0,};
	for(int i=1; i<=n; i++)
	{
		scanf("%d %d",&work[i].days,&work[i].money);
	}
	
	int dp[n+5]={0,}; // n일에 얻을수잇는최대돈 
	
	for(int i=n; i>0; i--)
	{
		int d = i+work[i].days;//오늘+일기간 
		if(d>n+1) //n+1보다 크면 기존꺼 
		{
			dp[i]=dp[i+1];
		}
		else
		{
			dp[i]=dp[i+1]<dp[d]+work[i].money?dp[d]+work[i].money:dp[i+1];
			//기존꺼보다 일하고 돈버는게 크면 넣기 
		}
	}
	
	printf("%d",dp[1]);
	
	return 0;
}
