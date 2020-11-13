#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <map>

#define MAX 130

using namespace std;

int N;

vector<pair<pair<int, int>, int> > graph[MAX][MAX];
map<pair<int,int>, int> dist;

int maze[MAX][MAX];

void dijkstra(pair<int,int> startIdx)
{
	for(int i=0; i<MAX; i++)
	{
		for(int j=0; j<MAX; j++)
		{	
			dist[make_pair(i,j)]=1e9;
		}
	}
	dist[startIdx]=0;
	
	priority_queue<pair<int, pair<int, int> > > pq;
	pq.push(make_pair(0,startIdx));
	
	while(pq.size())
	{
		pair<int, int> curIdx = pq.top().second;
		int curDist = -pq.top().first;
		pq.pop();
		//if(dist[curIdx] != 1e9) continue;
		if(dist[curIdx] < curDist) continue;
		//dist[curIdx]=curDist;
		for(int i=0; i<graph[curIdx.first][curIdx.second].size(); i++)
		{
			pair<int,int> nextIdx = graph[curIdx.first][curIdx.second][i].first;
			int nextDist = curDist + graph[curIdx.first][curIdx.second][i].second;
			
			//if(dist[curIdx] != 1e9) continue;
			
			if(dist[nextIdx] > nextDist)
			{
				dist[nextIdx] = nextDist;
				pq.push(make_pair(-nextDist,nextIdx));
			}
		}
	}
}

//int dx[4] = {1,-1,0,0};
//int dy[4] = {0,0,1,-1};
int dx[2]={1,0};
int dy[2]={0,1};

int main()
{
	int cnt=0;
	while(true)
	{
		scanf("%d",&N);
		if(!N) break;
		
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				scanf("%1d",&maze[i][j]);
				graph[i][j].clear();
			}
		}
		
		
		
		dist.clear();
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				for(int k=0; k<2; k++)
				{
					int ni = i + dx[k];
					int nj = j + dy[k];
					
					if(ni<1 || N<ni || nj<1 || N<nj) continue;
					
					graph[i][j].push_back(make_pair(make_pair(ni,nj),maze[ni][nj]));
					graph[ni][nj].push_back(make_pair(make_pair(i,j),maze[i][j]));
				}
			}
		}
		dijkstra(make_pair(1,1));
		
		printf("Problem %d: %d\n",++cnt,maze[1][1] + dist[make_pair(N,N)]);
	}
	
	return 0;
}
