#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define FUCK 987654321
	
vector<int> mul2;

int dp[100005];
	
int f(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	if(dp[n]!=FUCK) return dp[n];
	
	int idx = upper_bound(mul2.begin(),mul2.end(),n) - mul2.begin();
	
	if(n==mul2[idx-1]) return 1;
	
	int ret=987654321;
	for(int i=1; i<=idx; i++)
	{
		//if(mul2[idx-i]*2 > n) break;
		ret = min(ret,f(n-mul2[idx-i]) + f(mul2[idx-i]));
	}
	return ret;
}

int main()
{
	int N;
	scanf("%d",&N);
	
	for(int i=0; i<=N; i++) dp[i]=i;
	
	for(int i=1;; i++)
	{
		if(i*i>100000) break;
		
		mul2.push_back(i*i);
		dp[i*i]=1;
	}	
	
	for(int i=2; i<=N; i++)
	{
		//int idx = upper_bound(mul2.begin(),mul2.end(),i) - mul2.begin() -1;
		for(int j=2; j*j<=i; j++)
		{
			dp[i] = min(dp[i],dp[i - j*j]+1);
		}
	}
	
	printf("%d",dp[N]);
	
	return 0;
}
