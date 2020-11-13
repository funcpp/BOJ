#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int height[n+1];
	for(int i=0; i<n; i++)
	{
		scanf("%d",height+i);
	}
	
	int ans=0;
	for(int i=0; i<n; i++)
	{
		int p=height[i];
		int cnt=0;
		for(int j=i+1; j<n; j++)
		{
			if(height[j]>p) break;
			else cnt++;
		}
		ans=ans<cnt?cnt:ans;
	}
	
	printf("%d",ans);
	
	return 0;
}
