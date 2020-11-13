#include <stdio.h>
#include <vector>
#include <map>
#define uint64_t unsigned long long

using namespace std;


int N,M;
int s, e;

vector<pair<int, int> > graph[100005];

bool can;
map<int, bool> visited;

void dfs(int idx, int k)
{
	if(idx==e)
	{
		can=true;
		return;
	}
	
	for(int i=0; i<graph[idx].size(); i++)
	{
		int next = graph[idx][i].first;
		if(graph[idx][i].second >= k && !visited.count(next))
		{
			visited[next]=true;
			dfs(next,k);
		}
	}
}

int main()
{
	scanf("%d %d",&N, &M);
	scanf("%d %d",&s, &e);
	
	for(int i=0; i<M; i++)
	{
		int h1, h2, k;
		scanf("%d %d %d",&h1, &h2, &k);

		graph[h1].push_back(make_pair(h2,k));
		graph[h2].push_back(make_pair(h1,k));
	}
	
	uint64_t ans=0;
	uint64_t left=1, right = 1000000;
	while(left <= right)
	{
		uint64_t mid = (left+right)/2;
		
		can=false;
		visited.clear();
		dfs(s,mid);
		
		if(can)
		{
			left = mid+1;
			ans=max(ans,mid);
		}
		else
			right = mid-1;
	}
	
	printf("%llu",ans);
	
	
	return 0;
}
