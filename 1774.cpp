//¤µ¤²¿ÖÆ²·Á!!!!!!
#include <stdio.h>
#include <vector>
#include <utility>
#include <map>
#include <math.h>
#include <queue>
using namespace std;
#define int64 long long int
#define pii pair<int,int>
#define pll pair<double,double>
double calc(pll a, pll b)
{
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int prt[1005];

int find(int a)
{
	if(a==prt[a]) return a;
	return prt[a] = find(prt[a]);
}

int merge(int a, int b)
{
	a=find(a);
	b=find(b);
	
	if(a==b) return 0;
	
	prt[a]=b;
	
	return 1;
}



int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	vector<pii > coord(N+2,pll());
	for(int i=1; i<=N; i++)
	{	
		scanf("%d %d",&coord[i].first,&coord[i].second);
		prt[i]=i;
	}
	
	for(int i=0; i<M; i++)
	{
		int a, b;
		scanf("%d %d",&a,&b);
		merge(a,b);
	}
	
	priority_queue<pair<double, pii> > pq;
	
	for(int i=1; i<=N; i++)
	{
		for(int j=i+1; j<=N; j++)
		{
			
			pq.push({-calc(coord[i],coord[j]),{i,j}});
			
		}
	}
	
	double ans = 0;
	
	int edge_cnt=M;
	while(!pq.empty() && edge_cnt != N-1)
	{
		double cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		
		if(merge(x,y))
		{	
			ans+= sqrt(cost);
			edge_cnt++;
		}
	}
	
	printf("%.2lf",ans);
	
	return 0;
}
