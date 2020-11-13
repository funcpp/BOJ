#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> graph[10005];
vector<int> rgraph[10005];
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

void dfs_r(int x, vector<int>& ans)
{
	ans.push_back(x);
	
	visited[x]=true;
	
	for(int i=0; i<rgraph[x].size(); i++)
	{
		int nx = rgraph[x][i];
		
		if(!visited[nx]) dfs_r(nx,ans);
	}
	
	return;
}

int main()
{
	scanf("%d %d",&V,&E);
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
	for(int i=V-1; i>=0; i--)
	{
		if(visited[stack[i]]) continue;
		vector<int> comp;
		dfs_r(stack[i], comp);
		
		sort(comp.begin(),comp.end());
		SCC.push_back(comp);
	}
	
	sort(SCC.begin(), SCC.end(), [](vector<int> a, vector<int> b) -> bool
	{
		return a[0]<b[0];	
	});
	
	printf("%d\n",SCC.size());
	for(int i=0; i<SCC.size(); i++)
	{
		for(int k=0; k<SCC[i].size(); k++)
		{
			printf("%d ",SCC[i][k]);
		}
		printf("-1\n");
	}
	
	return 0;
}
