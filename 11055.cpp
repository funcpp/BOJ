#include<bits/stdc++.h>
int main()
{
	int N;
	scanf("%d",&N);
	int a[N+5]={0,};
	int dp[N+5]={0,};
	for(int i=0;i<N;i++){
		scanf("%d",a+i);
	}
	
	dp[0]=a[0];
	int ans = dp[0];
	for(int i=1;i<N;i++)
	{
		dp[i]=a[i];
		for(int j=0;j<i;j++){
			if(a[j] < a[i])
				dp[i] = std::max(dp[i], dp[j]+a[i]);
		}
		ans=std::max(ans,dp[i]);
	}
	
	printf("%d",ans);
	
	return 0;
}
