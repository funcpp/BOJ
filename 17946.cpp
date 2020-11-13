#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> ks;
	int max=0;
	for(int i=0; i<n; i++)
	{
		int k;
		scanf("%d",&k);
		//ks.push_back(k);
		//if(max<k) max=k;
		printf("1\n");
	}
	
	/*long long dp[max+5] = {0,};
	dp[0]=1;
	dp[1]=2;
	dp[2]=4;
	dp[3]=7;
	
	for(int i=4; i<=max; i++)
	{
		dp[i]=dp[i-1]+i;
	}
	
	for(int i=0; i<n; i++)
	{
		printf("%d\n",dp[ks[i]] - (dp[ks[i]]-1)); 
	}*/
	
	return 0;
}
