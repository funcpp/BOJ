#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int nums[15];

int s[15];
int use[15];

void dfs(int cnt, int idx)
{
	if(cnt==6)
	{
		for(int i=0; i<6; i++)
		{
			printf("%d ",s[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=idx; i<n; i++)
	{
		s[cnt]=nums[i];
		dfs(cnt+1,i+1);
	}
	
	return;
}

int main()
{
	while(true)
	{
		scanf("%d",&n);
		if(n==0) break;
		
		for(int i=0; i<n; i++)
		{
			scanf("%d",nums+i);
		}
		
		dfs(0,0);
		printf("\n");
	}
	return 0;
}
