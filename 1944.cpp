#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>
#include <map>
#include <string.h>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<pair<int, int> > v;

int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	int maze[N+1][N+1]={0,};
	
	map<pair<int,int>,int > nodeNum;
	
	pair<int, int> startPoint;
	
	int tmp=0;
	for(int i=0; i<N; i++)
	{
		char c[N+2]={0,};
		scanf("%s",c);
		for(int j=0; j<N; j++)
		{
			if(c[j]=='1') maze[i][j]=1;
			else if(c[j]=='0') maze[i][j]=0;
			else if(c[j]=='S')
			{
				maze[i][j]=2;
				v.push_back(make_pair(i,j));
				nodeNum[make_pair(i,j)]=tmp++;
				startPoint=make_pair(i,j);
			}
			else if(c[j]=='K')
			{
				maze[i][j]=3;
				v.push_back(make_pair(i,j));
				nodeNum[make_pair(i,j)]=tmp++;
			}
		}
	}
	
	vector<pair<int, int> > tree[v.size()+2];
	
	for(int i=0; i<v.size(); i++)
	{
		map<pair<int, int>, int > visited;
		
		int x = v[i].first;
		int y = v[i].second;
		
		queue<pair<int,int> > q;
		q.push(v[i]);
		visited[v[i]]=1;
		
		while(!q.empty())
		{
			pair<int, int> front = q.front();
			int x = front.first;
			int y = front.second;
			q.pop();
			
			for(int j=0; j<4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				
				if(nx <0 || nx>=N || ny<0 || ny>=N) continue;
				
				if(!visited.count(make_pair(nx,ny)) && maze[nx][ny]!=1)
				{
					visited[make_pair(nx,ny)] = visited[front]+1;
					q.push(make_pair(nx,ny));
					
					if(2<=maze[nx][ny])
					{
						tree[i].push_back(make_pair(nodeNum[make_pair(nx,ny)], visited[make_pair(nx,ny)]-1));
					}
				}
			}
		}
	}

	map<pair<int, int>, int > visited;
	
	priority_queue<pair<long long, pair<int, int> > > pq;
	for(int i=0; i<tree[nodeNum[startPoint]].size(); i++)
	{
		int next = tree[nodeNum[startPoint]][i].first;
		long long cost = tree[nodeNum[startPoint]][i].second;
		pq.push(make_pair(-cost,v[next]));
	}
	
	visited[startPoint]=true;
	
	long long ans=0;
	
	while(!pq.empty())
	{
		long long cost = -pq.top().first;
		pair<int, int> cur = pq.top().second;
		pq.pop();
		
		if(!visited[cur])
		{
			visited[cur]=true;
			ans = ans + cost;
			
			for(int i=0; i<tree[nodeNum[cur]].size(); i++)
			{
				int next = tree[nodeNum[cur]][i].first;
				long long newCost = tree[nodeNum[cur]][i].second;
				
				if(!visited[v[next]])
					pq.push(make_pair(-newCost,v[next]));
			}
		}
	}
	
	for(int i=0; i<v.size(); i++)
	{
		if(!visited.count(v[i]))
		{
			printf("-1");
			return 0;
		}
	}
	
	
	printf("%lld",ans);
	
	return 0;
}
