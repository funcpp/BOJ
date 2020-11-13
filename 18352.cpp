#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int N,M,K,X;
vector<vector<int> > v;
vector<int> dist;
int main()
{
	scanf("%d %d %d %d",&N,&M,&K,&X);
	v=vector<vector<int> >(N+1,vector<int>());
	dist=vector<int>(N+1,0);
	for(int i=0; i<M; i++)
	{
		int from,to;
		scanf("%d %d",&from,&to);
		v[from].push_back(to);
	}	
	
	for(int i=1; i<=N; i++) if(i!=X) dist[i]=1e9;
	
	priority_queue<pair<int, int> > pq;
	pq.push({0,X});
	
	while(!pq.empty())
	{
		int d = -pq.top().first;
		int x = pq.top().second;
		pq.pop();
		
		for(auto nx : v[x])
		{
			if(dist[nx] > d+1)
			{
				dist[nx] = d+1;
				pq.push({-dist[nx],nx});
			}
		}
	}
	
	bool a=false;
	for(int i=1; i<=N; i++)
	{
		if(dist[i]==K)
		{
			a=true;
			printf("%d ",i);
		}
	}
	if(!a) printf("-1");
	
	return 0;
}
