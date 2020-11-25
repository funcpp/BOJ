#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	vector<long long int> dp(1000005);
	dp[0]=0;
	dp[1]=0;
	dp[2]=1;
	dp[3]=2;
	dp[4]=9;
	
	for(int i=5;i<=N;i++){
		dp[i]=(i-1)%1000000000 * (dp[i-1]+dp[i-2])%1000000000;
	}
	printf("%d",dp[N]%1000000000);
}
