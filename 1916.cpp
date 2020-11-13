#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N, M;

vector<pair<int, int> > graph[10001];
int dist[10001];

void dijkstra(int startIdx)
{
	for(int i=0; i<10001; i++)
	{
		dist[i]=1e9;
	}
	dist[startIdx]=0;
	
	//<최단거리, 위치 쌍> 
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0,startIdx));
	
	while(pq.size())
	{
		int curIdx = pq.top().second;
		int curDist = -pq.top().first;
		pq.pop();
		//if(dist[curIdx] != 1e9) continue;
		if(dist[curIdx] < curDist) continue;
		//dist[curIdx]=curDist;
		for(int i=0; i<graph[curIdx].size(); i++)
		{
			int nextIdx = graph[curIdx][i].first;
			int nextDist = curDist + graph[curIdx][i].second;
			
			//if(dist[curIdx] != 1e9) continue;
			
			if(dist[nextIdx] > nextDist)
			{
				dist[nextIdx] = nextDist;
				// 발견한 지점을 pq에 넣어준다. 
				pq.push(make_pair(-nextDist,nextIdx));
			}
		}
	}
}

int main()
{
	scanf("%d %d",&N,&M);
	
	for(int i=0; i<M; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		
		graph[a].push_back(make_pair(b,c));
	}

	int x,y;
	scanf("%d %d",&x,&y);
	dijkstra(x);
	printf("%d",dist[y]);
	return 0;
}
