#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>

using namespace std;

int main()
{
	int V,E;
	scanf("%d %d",&V,&E);
	
	vector<pair<int, int> > v[V+2];
	
	for(int i=0; i<E; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	
	bool visited[V+1]={0,};
	
	priority_queue<pair<double, int> > pq;
	for(int i=0; i<v[1].size(); i++)
	{
		int next = v[1][i].first;
		double cost = v[1][i].second;
		pq.push(make_pair(-cost,next));
	}
	
	visited[1]=true;
	
	int ans=0;
	
	while(!pq.empty())
	{
		double cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		
		if(!visited[cur])
		{
			visited[cur]=true;
			ans = ans + cost;
			
			for(int i=0; i<v[cur].size(); i++)
			{
				int next = v[cur][i].first;
				int newCost = v[cur][i].second;
				
				if(!visited[next])
					pq.push(make_pair(-newCost,next));
			}
		}
	}
	
	printf("%d",ans);
	
	return 0;
}
