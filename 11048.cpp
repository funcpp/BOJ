#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[1005][1005], dp[1005][1005];

int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			dp[i][j] = max(i&&j?dp[i-1][j-1]:0,max(i?dp[i-1][j]:0,j?dp[i][j-1]:0))+arr[i][j];
		}
	}
	printf("%d",dp[N-1][M-1]);
	
	return 0;
}
