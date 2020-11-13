#include <bits/stdc++.h>
using namespace std;

int line[1005][1005];
int check[1005];
int n,m,v;

void dfs(int idx)
{
	check[idx]=1;
	
	for(int i=1; i<=n; i++)
	{
		if(i==idx) continue;
		
		if(line[idx][i] && check[i]==0)
		{
			printf("%d ",i);
			dfs(i);
		}
	}
	
	return;
}


void bfs(int idx)
{
	queue<int> q;
	q.push(idx);
	check[idx]=1;
	while(!q.empty())
	{
		idx=q.front();
		printf("%d ",idx);
		q.pop();
		for(int i=1; i<=n; i++)
		{
			if(line[idx][i] && !check[i])
			{
				q.push(i);
				check[i]=1;
			}
		}
	}
}

int main()
{
	scanf("%d %d %d",&n,&m,&v);
	
	for(int i=0; i<m; i++)
	{
		int t,t1;
		scanf("%d %d",&t,&t1);
		
		line[t][t1]=1;
		line[t1][t]=1;
	}
	
	check[v]=1;
	printf("%d ",v);
	for(int i=1; i<=n; i++)
	{
		if(i==v) continue;
		
		if(line[v][i] && !check[i])
		{
			printf("%d ",i);
			dfs(i);
		}
	}
	
	printf("\n");
	memset(check,0,sizeof(check));
	bfs(v);
	return 0;
}
