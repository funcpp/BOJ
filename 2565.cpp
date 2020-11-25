#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	int arr[505]={0,};
	for(int i=0,a,b;i<N;i++){
		scanf("%d %d",&a,&b);
		arr[a]=b;
	}
	vector<int> v;
	for(int i=0;i<505;i++){
		if(arr[i])
			v.push_back(arr[i]);
	}
	
	int sub =0;
	int dp[505]={0,};
	dp[0]=1;
	for(int i=1; i<v.size();i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(v[j] < v[i]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		sub=max(sub,dp[i]);
	}
	printf("%d",N-sub);
	
	return 0;
}
