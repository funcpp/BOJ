#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[500001];
vector<int> rgraph[500001];
vector<int> stack;
map<int, bool> visited;
	
int money[500001];

int V,E;
int S,P;

vector<vector<int> > SCC;
vector<vector<int> > SCCGraph;

int component_num[500001];
int component_money[500001];
int start_component_num;
	
int max_money[500001];


map<pair<int,int>, bool> chk;
vector<int> res;

vector<int> inOrder;
queue<int> q;
	
void dfs(int x)
{
	visited[x]=true;
	
	
	for(auto next : graph[x])
	{
		if(visited[next]) continue;
		dfs(next);
	}
	/*
	for(int i=0; i<graph[x].size(); i++)
	{
		int nx = graph[x][i];
		
		if(!visited[nx]) dfs(nx);
	}
	*/
	
	stack.push_back(x);
	
	return;
}

//void dfs_r(int x, vector<int>& ret)
void dfs_r(int x)
{
	visited[x]=true;
	
	for(auto next : rgraph[x])
	{
		if(visited[next]) continue;
		dfs_r(next);
	}
	/*
	for(int i=0; i<rgraph[x].size(); i++)
	{
		int nx = rgraph[x][i];
		
		if(!visited[nx]) dfs_r(nx,ret);
	}*/
	
	SCC.back().push_back(x);
	
	return;
}

int main()
{
	scanf("%d %d",&V,&E);
	//vector<int> money(V+1,0);
	//graph = vector<vector<int> >(V+1,vector<int>());
	//rgraph = vector<vector<int> >(V+1,vector<int>());
	
	while(E--)
	{
		int to,from;
		scanf("%d %d",&to,&from);
		graph[to].push_back(from);
		rgraph[from].push_back(to);
	}
	
	for(int i=1; i<=V; i++)
	{
		scanf("%d",&money[i]);
	}
	
	scanf("%d %d",&S,&P);
	for(int i=0; i<P; i++)
	{
		int a;
		scanf("%d",&a);
		res.push_back(a);
	}
	
	for(int i=1; i<=V; i++)
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}

	visited.clear();
	for(int i=V-1; i>=0; i--)
	{
		if(visited[stack[i]]) continue;
		SCC.push_back({});
		dfs_r(stack[i]);
		//vector<int> comp;
		//dfs_r(stack[i], comp);
		//SCC.push_back(comp);
	}
	
	SCCGraph.resize(SCC.size());
	inOrder.resize(SCC.size());
	//SCCGraph = vector<vector<int> >(SCC.size()+1,vector<int>());
	//vector<int> component_num(V+2,0);
	
	for(int i=0; i<SCC.size(); i++)
	{
		for(int j : SCC[i])
		{
			component_num[j]=i;
			component_money[i]+=money[j];
			if(j==S) start_component_num = i;
		}
	}
	
	/*
	for(int i=1; i<=V; i++)
	{
		printf("%d ",component_num[i]);
	}
	printf("\n");*/
	
	
	for(int a=0; a<=V; a++)
	{
		for(int b : graph[a])
		{
			int cid_a = component_num[a];
			int cid_b = component_num[b];
			
			//printf("%d %d\n",cid_a,cid_b);
			
			if(cid_a ==cid_b) continue;
			if(chk.count({cid_a, cid_b})) continue;
			chk[{cid_a, cid_b}]=true;
			SCCGraph[cid_a].push_back(cid_b);
			inOrder[cid_b]++;	
		}
	}
	
	/*
	for(int i=0; i<SCCGraph.size(); i++)
	{
		for(auto j : SCCGraph[i])
		{
			printf("%d %d\n",i,j);
		}
	}*/
	
	
	
	max_money[start_component_num]=component_money[start_component_num];
	
	for(int i=0; i<inOrder.size(); i++)
	{
		if(!inOrder[i]) q.push(i);
	}
	
	while(!q.empty())
	{
		int idx = q.front(); q.pop();
		
		for(auto a : SCCGraph[idx])
		{
			inOrder[a]--;
			if(!max_money[idx]) max_money[a] = max(max_money[a],0);
			else max_money[a] = max(max_money[a], max_money[idx] + component_money[a]);
			
			if(!inOrder[a]) q.push(a);
		}
	}
	
	//vector<long long> max_money(SCC.size()+1,0);
	
	/*q.push(start_component_num);
	max_money[start_component_num]=component_money[start_component_num];
	
	while(!q.empty())
	{
		int idx = q.front();
		q.pop();
		
		for(int a : SCCGraph[idx])
		{
			max_money[a] = max(max_money[a], max_money[idx] + component_money[a]);
			q.push(a);
		}
	}*/
	
	int ans = 0;
	/*for(int i=0; i<SCC.size()+1; i++)
	{
		if(isResComponent[i])
		{
			ans = max(ans,max_money[i]);
		}
	}*/
	for(int i=0; i<P; i++)
	{
		ans = max(ans, max_money[component_num[res[i]]]);
	}
	printf("%d",ans);
	
	return 0;
}
