#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int dp[n+5]={0,};
	int arr[n+5]={0,};
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
	}
	dp[0]=0;
	dp[1]=arr[1];
	dp[2]=dp[1]+arr[2];
	dp[3]=max(arr[1], arr[2])+arr[3];
	for(int i=4;i<=n;i++){
		dp[i]=max(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]);
	}
	printf("%d",dp[n]);
	return 0;
}
