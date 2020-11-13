#include <bits/stdc++.h>
int main()
{
	int n;
	scanf("%d",&n);
	
	int arr[n+2]={0,};
	for(int i=1; i<=n; i++)
	{
		scanf("%d",arr+i);
	}
	
	long long int dp[n+1]={0,};
	
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		int min=0;
		for(int j =0; j<i; j++)
		{
			if(arr[i] > arr[j])
			{
				if(min < dp[j]) min = dp[j];
			}
		}
		dp[i]=min+1;
		if(ans < dp[i]) ans = dp[i];
	}
	
	printf("%d",ans);
	
	return 0;
}
