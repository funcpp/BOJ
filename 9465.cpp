#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		
		int arr[n+5][2]={0,};
		int dp[n+5][2]={0,};
		
		for(int i=0;i<2;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&arr[j][i]);
			}
		}
		
		dp[0][0]=arr[0][0];
		dp[0][1]=arr[0][1];
		dp[1][0]=dp[0][1]+arr[1][0];
		dp[1][1]=dp[0][0]+arr[1][1];
		for(int i=2;i<n;i++){
			dp[i][0]=max(dp[i-2][1]+arr[i][0],dp[i-1][1]+arr[i][0]);
			dp[i][1]=max(dp[i-2][0]+arr[i][1],dp[i-1][0]+arr[i][1]);
		}
		printf("%d\n",max(dp[n-1][0],dp[n-1][1]));
	}
	return 0;
}
