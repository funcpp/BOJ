#include <stdio.h>
int n,m;
int line[1005][1005];
int check[1005];
void dfs(int idx)
{
	check[idx]=1;
	for(int i=1; i<=n; i++)
	{
		if(line[idx][i] && !check[i])
		{
			dfs(i);
		}
	}
}

int main()
{
	int ans=0;
	
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		line[u][v]=1;
		line[v][u]=1;
	}
	
	for(int i=1; i<=n; i++)
	{
		if(!check[i])
		{
			dfs(i);
			ans++;
		}
	}
	
	printf("%d",ans);
	
	return 0;
}
