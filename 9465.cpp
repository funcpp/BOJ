#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		int N;
		scanf("%d",&N);
		
		int arr[N+5][2];
		for(int j=0;j<2;j++) for(int i=0;i<N;i++) scanf("%d",&arr[i][j]);
		
		int dp[N+5][3] = {0,};
		dp[0][0]=arr[0][0];
		dp[0][1]=arr[0][1];
		dp[0][2]=0;
		
		for(int i=1;i<N;i++){
			dp[i][0] = max(dp[i-1][1] + arr[i][0], dp[i-1][2]+arr[i][0]);
			dp[i][1] = max(dp[i-1][0] + arr[i][1], dp[i-1][2]+arr[i][1]);
			dp[i][2] = max(dp[i-1][0], dp[i-1][1]);
		}
		
		printf("%d\n",max(max(dp[N-1][0], dp[N-1][1]), dp[N-1][2]));
	}
	return 0;
}
