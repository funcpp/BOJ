#include<bits/stdc++.h>
using namespace std;
int N,ans;

int arr[100001][2];
void bf(int idx, int cnt){
	if(idx==N){
		ans++;
		return;
	}
	
	if(!idx){
		arr[idx][0]=1;
		bf(idx+1,cnt+1);
		arr[idx][0]=0;
		arr[idx][1]=1;
		bf(idx+1,cnt+1);
		arr[idx][1]=0;
		bf(idx+1,cnt);
	}
	else{
		if(!arr[idx-1][0]){
			arr[idx][0]=1;
			bf(idx+1,cnt+1);
			arr[idx][0]=0;
		}
		
		if(!arr[idx-1][1]){
			arr[idx][1]=1;
			bf(idx+1,cnt+1);
			arr[idx][1]=0;
		}
		
		bf(idx+1,cnt);
	}
}

int main()
{
	/*for(int i=1;i<11;i++){
		ans=0;
		N=i;
		bf(0,0);
		printf("%d ",ans);
	}*/
	
	scanf("%d",&N);
	int dp[N+5]={0,};
	dp[1]=3;
	dp[2]=7;
	for(int i=3;i<=N;i++){
		dp[i]=(dp[i-1]*2)%9901+dp[i-2]%9901;
	}
	printf("%d",dp[N]%9901);
}
