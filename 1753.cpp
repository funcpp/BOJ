#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int V,E;
int start;
int dist[20005];

vector<pair<int,int> > v[20005];

int main()
{
	scanf("%d %d",&V,&E);
	scanf("%d",&start);
	for(int i=0; i<E; i++)
	{
		int u,v_,w;
		scanf("%d %d %d",&u,&v_,&w);
		v[u].push_back({v_,w});
	}
	
	for(int i=1; i<=V; i++)
	{
		if(i!=start) dist[i]=1e9;
	}

	priority_queue<pair<int,int> > q;
	q.push({0,start});
	
	while(!q.empty())
	{
		int d = -q.top().first;
		int x = q.top().second;
		q.pop();
		
		if(dist[x] < d) continue;
		
		//for(pair<int,int> p : v[x])
		for(int i=0; i<v[x].size(); i++)
		{
			int nx = v[x][i].first;
			int cost = v[x][i].second;
			
			if(dist[nx] > dist[x] + cost)
			{
				dist[nx] = dist[x] + cost;
				q.push({-dist[nx],nx});
			}
		}
	}
	
	for(int i=1; i<=V; i++)
	{
		if(dist[i]==1e9)
		{
			printf("INF\n");
		}
		else
		{
			printf("%d\n",dist[i]);
		}
	}
}
