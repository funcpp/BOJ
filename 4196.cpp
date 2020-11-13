#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> graph[100005];
vector<int> rgraph[100005];
vector<int> stack;
map<int, bool> visited;
	
int V,E;

void dfs(int x)
{
	visited[x]=true;
	
	for(int i=0; i<graph[x].size(); i++)
	{
		int nx = graph[x][i];
		
		if(!visited[nx]) dfs(nx);
	}
	
	stack.push_back(x);
	
	return;
}

void dfs_r(int x, vector<int>& ret)
{
	ret.push_back(x);
	
	visited[x]=true;
	
	for(int i=0; i<rgraph[x].size(); i++)
	{
		int nx = rgraph[x][i];
		
		if(!visited[nx]) dfs_r(nx,ret);
	}
	
	return;
}

int T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&V,&E);
		for(int i=1; i<=V; i++)
		{
			graph[i].clear();
			rgraph[i].clear();
		}
		visited.clear();
		stack.clear();
		
		while(E--)
		{
			int to,from;
			scanf("%d %d",&to,&from);
			graph[to].push_back(from);
			rgraph[from].push_back(to);
		}
		
		for(int i=1; i<=V; i++)
		{
			if(!visited[i])
			{
				dfs(i);
			}
		}	
		
		//for(int i=0; i<V; i++) printf("%d ",stack[i]);
		
		visited.clear();
		vector<vector<int> > SCC;
		int ans=0;
		for(int i=V-1; i>=0; i--)
		{
			if(visited[stack[i]]) continue;
			vector<int> comp;
			dfs_r(stack[i], comp);
			SCC.push_back(comp);
		}
		
		int scc[100005] = {0,};
		for(int i=1; i<=SCC.size(); i++)
		{
			for(int j=0; j<SCC[i].size(); i++)
			{
				scc[SCC[i][j]]=i;
			}
		}
		
		map<int, bool> chk[100005];
		vector<int> newGraph[100005];
		for(int v=1; v<=V; v++)
		{
			for(int j=0; j<graph[v].size(); j++)
			{
				int u = graph[v][j];
				
				if(scc[u] != scc[v] && !chk[scc[v]][scc[u]])
				{
					chk[scc[v]][scc[u]]=true;
					newGraph[scc[v]].push_back(scc[u]);
				}
			}
		}
		
		// SCC의 그래프에 위상정렬 사용해서도 풀어보려고했는데 실패.. 
		
	}
	return 0;
}
