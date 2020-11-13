#include <stdio.h>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

#define MAX 100005

vector<int> tree[MAX];
map<pair<int,int>,int> dist;
int depth[MAX];
int parent[20][MAX];
int minLen[20][MAX];
int maxLen[20][MAX];

int N,K;

void dfs(int x)
{
	for(int i=0; i<tree[x].size(); i++)
	{
		int child = tree[x][i];
		if(depth[child]) continue;

		depth[child] = depth[x]+1;
		parent[0][child]=x;
		minLen[0][child]=dist[{x,child}];
		maxLen[0][child]=dist[{x,child}];
		dfs(child);
	}
}

struct AANSWER
{
	int min,max,idx;	
};

AANSWER LCA(int a, int b)
{
	if(a==b) return {(int)1e8,0,a};
	if(depth[a] > depth[b]) return LCA(b,a);
	else if(depth[a] < depth[b])
	{
		int diff = depth[b] - depth[a];
		for(int k = 19; k >= 0; k--)
		{
	            if(diff >= (1 << k))
				{
	                AANSWER ret = LCA(a, parent[k][b]);
	                int newMin = min(minLen[k][b], ret.min);
	                int newMax = max(maxLen[k][b], ret.max);
	                return {newMin, newMax, ret.idx};
	            }
		}
	}
	
	if(parent[0][a]==parent[0][b]) return {min(minLen[0][a],minLen[0][b]),max(maxLen[0][a], maxLen[0][b]),parent[0][a]};
	
	for(int k=19; k>=0; k--)
	{
		if(parent[k][a] != parent[k][b])
		{
            AANSWER ret = LCA(parent[k][a], parent[k][b]);
            int newMin = min(min(minLen[k][a], minLen[k][b]), ret.min);
            int newMax = max(max(maxLen[k][a], maxLen[k][b]), ret.max);
            return {newMin, newMax, ret.idx};
        }
	}
}

int main()
{
	scanf("%d",&N);
	
	for(int i=0; i<N-1; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		
		tree[a].push_back(b);
		tree[b].push_back(a);
		dist[{a,b}]=c;
		dist[{b,a}]=c;
	}
	
	depth[1]=1;
	dfs(1);
	
	for(int i=1; i<20; i++)
	{
		for(int j=1; j<=N; j++)
		{
			int mid = parent[i-1][j];
			parent[i][j] = parent[i-1][mid];
			minLen[i][j] = min(minLen[i-1][j], minLen[i-1][mid]);
			maxLen[i][j] = max(maxLen[i-1][j], maxLen[i-1][mid]);
		}
	}
	
	scanf("%d",&K);
	
	vector<pair<int, int> > v(K);
	
	for(int i=0; i<K; i++)
	{
		scanf("%d %d",&v[i].first, &v[i].second);
	}
	
	for(int i=0; i<K; i++)
	{
		AANSWER ans = LCA(v[i].first, v[i].second);
		
		printf("%d %d\n",ans.min,ans.max);
	}
	
	return 0;
}
