#include <stdio.h>
#include <vector>
#include <queue>
//#include <priority_queue>
#include <utility>
using namespace std;
#define pii pair<long long int,long long int>
int N,E;
vector<pii> v[1000];

int v1, v2;

void dijkstra(int start, vector<long long int>& ret)
{
	ret = vector<long long int>(N+1, 0x7f7f7f7f);
	ret[start] = 0;
	
	priority_queue<pii> pq;
	pq.push({0, start});
	
	while(pq.size())
	{
		long long int w = -pq.top().first;
		long long int current = pq.top().second;
		pq.pop();
		
		if(ret[current] < w) continue;
		
		for(pii npii : v[current])
		{
			long long int nx = npii.first;
			long long int nw = npii.second;
			
			if(ret[nx] > w+nw)
			{
				ret[nx]=w+nw;
				pq.push({-w-nw,nx});
			}
		}
	}
	return;
}

int main()
{
	scanf("%d %d",&N,&E);
	for(int i=0;i<E;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	
	scanf("%d %d",&v1,&v2);
	
	// 1 -> v1 까지
	// 1 -> v2 까지
	// v1 -> N 까지
	// v2 -> N 까지
	
	// 1 -> v1 -> v2 -> N
	// 1 -> v2 -> v1 -> N
	
	vector<long long int> v0_, v1_, v2_;
	dijkstra(1,v0_);
	dijkstra(v1,v1_);
	dijkstra(v2,v2_);
	
	long long int ans = min(v0_[v1] + v1_[v2] + v2_[N], v0_[v2] + v2_[v1] + v1_[N]);
	
	if(ans>=0x7f7f7f7f)
	{
		printf("-1");
	}
	else
	{
		printf("%lld",ans);
	}
	
	 
	
	return 0;
}
