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
	for(int i=0;i<2;i++)
		for(int j=1;j<7;j++)
			ans += arr[i][j]%K ? arr[i][j]/K+1 : arr[i][j]/K;
			
	printf("%d",ans);
	
	return 0;
}
