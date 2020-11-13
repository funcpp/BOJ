#include <stdio.h>
int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	
	int a[105]={0,};
	int dp[K+5]={0,};
	
	for(int i=0;i<N;i++){
		scanf("%d",a+i);
	}
	
	dp[0]=1;
	for(int i=0;i<N;i++){
		for(int j=a[i];j<=K;j++){
			dp[j] += dp[j - a[i]];
		}
	}
	printf("%d",dp[K]);
	return 0;
}
