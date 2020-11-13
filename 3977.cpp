#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <memory.h>
using namespace std;

int T;
int N,M;
vector<vector<int> > SCC;
vector<int> _graph[100001];
vector<int> _rgraph[100001];

vector<int> stack;
//map<int, bool> _visited;
bool _visited[100001];
vector<int> _SCCGraph[100001];
int component_num[100001];
map<pair<int,int>, bool> chk;
//bool chk[100001][100001];

int inOrder[100001];

void dfs(int x)
{
	_visited[x]=true;
	for(auto nx : _graph[x])
	{
		if(!_visited[nx]) dfs(nx);
	}
	
	stack.push_back(x);
	return;
}

void dfs_r(int x)
{
	_visited[x]=true;
	for(auto nx : _rgraph[x])
	{
		if(!_visited[nx]) dfs_r(nx);
	}
	
	SCC.back().push_back(x);
	return;
}

int main()
{
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d %d",&N,&M);
		
		SCC.clear();
		for(int i=0; i<N; i++)
		{
			_graph[i].clear();
			_rgraph[i].clear();
			
			_SCCGraph[i].clear();
			component_num[i]=0;
			inOrder[i]=0;
		}
		
		for(int i=0; i<M; i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			
			_graph[a].push_back(b);
			_rgraph[b].push_back(a);
		}
		
		//_visited.clear();
		memset(_visited,false,sizeof(_visited));
		for(int i=0; i<N; i++)
		{
			if(!_visited[i])
			{
				dfs(i);
			}
		}
		//_visited.clear();
		memset(_visited,false,sizeof(_visited));
		stack.clear();
		for(int i=N-1; i>=0; i--)
		{
			if(!_visited[stack[i]])
			{
				SCC.push_back({});
				dfs_r(stack[i]);
			}
		}
		/*
		if(SCC.size() == N)
		{
			printf("Confused\n\n");
			continue;
		}*/
		
		for(int i=0; i<SCC.size(); i++)
		{
			for(int j : SCC[i])
			{
				component_num[j]=i;
			}
		}
		
		chk.clear();
		//memset(chk,false,sizeof(chk));
		for(int a=0; a<N; a++)
		{
			for(int b : _graph[a])
			{
				int cid_a = component_num[a];
				int cid_b = component_num[b];
				
				if(cid_a ==cid_b) continue;
				if(chk.count({cid_a, cid_b})) continue;
				chk[{cid_a, cid_b}]=true;
				_SCCGraph[cid_a].push_back(cid_b);
				inOrder[cid_b]++;	
			}
		}
		
		int inOrderZ=0;
		int cid=0;
		for(int i=0; i<SCC.size(); i++)
		{
			if(!inOrder[i])
			{
				cid=i;
				inOrderZ++;
			}
		}
		
		if(inOrderZ != 1)
		{
			printf("Confused\n\n");
			continue;
		}
		
		sort(SCC[cid].begin(), SCC[cid].end());
		for(auto x : SCC[cid])
		{
			printf("%d\n",x);
		}
		printf("\n");
	}
	return 0;
}
