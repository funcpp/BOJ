#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,K, arr[10][10]={0,};
	scanf("%d %d",&N,&K);
	for(int i=0,a,b;i<N;i++)
	{
		scanf("%d %d",&a,&b);
		arr[a][b]++;
	}
	
	int ans = 0;
	for(int j=1;j<4;j++)
		ans += j==1 ?
		(arr[0][j*2]+arr[1][j*2]+arr[0][j*2-1]+arr[1][j*2-1])%K ?
		(arr[0][j*2]+arr[1][j*2]+arr[0][j*2-1]+arr[1][j*2-1])/K+1 : 
		(arr[0][j*2]+arr[1][j*2]+arr[0][j*2-1]+arr[1][j*2-1])/K :
		(((arr[0][j*2]+arr[0][j*2-1])%K ? (arr[0][j*2]+arr[0][j*2-1])/K+1 : (arr[0][j*2]+arr[0][j*2-1])/K) +
		((arr[1][j*2]+arr[1][j*2-1])%K ? (arr[1][j*2]+arr[1][j*2-1])/K+1 : (arr[1][j*2]+arr[1][j*2-1])/K));
			
	printf("%d",ans);
	
	return 0;
}
