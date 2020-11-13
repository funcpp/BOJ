#include <stdio.h>
#include <vector>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

int floyd[55][55];

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(i==j) continue;
			floyd[i][j]=987654321;
		}
	}
	
	while(true)
	{
		int a, b;
		scanf("%d %d",&a,&b);
		if(a==-1 && b==-1) break;
		
		floyd[a][b]=1;
		floyd[b][a]=1;
	}
	
	for(int j=1; j<=n; j++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int k=1; k<=n; k++)
			{
				floyd[i][k] = min(floyd[i][k],floyd[i][j] + floyd[j][k]);
			}
		}
	}
	
	std::vector<int> ans;
	int cnt=0, Min=987654321;
	for(int i=1; i<=n; i++)
	{
		int m=0;
		for(int j=1; j<=n; j++)
		{
			if(floyd[i][j] && floyd[j][i])
			{
				m = max(m,floyd[i][j]);
			}
		}
		Min=min(Min,m);
	}
	
	for(int i=1; i<=n; i++)
	{
		int m=0;
		for(int j=1; j<=n; j++)
		{
			if(floyd[i][j] && floyd[j][i])
			{
				m = max(m,floyd[i][j]);
			}
		}
		if(m==Min)
		{
			cnt++;
			ans.push_back(i);
		}
	}
	
	printf("%d %d\n",Min,cnt);
	for(int i=0; i<ans.size(); i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
