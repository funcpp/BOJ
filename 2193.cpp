#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	
	long long int dp[100][2]={0,};
	dp[1][1]=1;
	dp[2][0]=1;
	
	for(int i=3;i<=N;i++){
		dp[i][0]=dp[i-1][0]+dp[i-1][1];
		dp[i][1]=dp[i-1][0];
	}
	
	printf("%lld",dp[N][0]+dp[N][1]);
	
	return 0;
}
