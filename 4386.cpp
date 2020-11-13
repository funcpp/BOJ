#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>

using namespace std;

double calcDist(pair<double,double> a, pair<double,double> b)
{
	return (a.first-b.first)*(a.first-b.first) + (a.second-b.second) * (a.second-b.second);
}

int main()
{
	int n;
	scanf("%d",&n);
	vector<pair<double,double> > v(n);
	vector<pair<int, double> > graph[n+1];
	
	for(int i=0; i<n; i++)
	{
		scanf("%lf %lf",&v[i].first,&v[i].second);
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			graph[i].push_back(make_pair(j,calcDist(v[i],v[j])));
			graph[j].push_back(make_pair(i,calcDist(v[i],v[j])));
		}
	}
	
	bool visited[n+1]={0,};
	
	priority_queue<pair<double, int> > pq;
	for(int i=0; i<graph[0].size(); i++)
	{
		int next = graph[0][i].first;
		double cost = graph[0][i].second;
		pq.push(make_pair(-cost,next));
	}
	visited[0]=true;
	
	double ans=0;
	
	while(!pq.empty())
	{
		double cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		
		if(!visited[cur])
		{
			visited[cur]=true;
			ans = ans + sqrtf(cost);
			
			for(int i=0; i<graph[cur].size(); i++)
			{
				int next = graph[cur][i].first;
				int newCost = graph[cur][i].second;
				
				if(!visited[next])
					pq.push(make_pair(-newCost,next));
			}
		}
	}
	
	printf("%lf",ans);
	
	return 0;
}
