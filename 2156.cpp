#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	int A[N+5]={0,};
	for(int i=1;i<=N;i++)
	{
		scanf("%d",A+i);
	}
	
	int dp[N+5]={0,};
	dp[0]=0;
	dp[1]=A[1];
	dp[2]=dp[1]+A[2];
	for(int i=3;i<=N;i++){
		dp[i]=max(max(dp[i-3]+A[i]+A[i-1], dp[i-2]+A[i]), dp[i-1]);

	}
	printf("%d",dp[N]);
		
	return 0;
}
