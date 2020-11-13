#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define uint64_t unsigned long long int

int N;

int world[55][55];
pair<int, int> startPoint;
vector<pair<int, int> > homeList;
int energy[55][55];

int dx[8] = {1,-1,0,0,1,-1,1,-1};
int dy[8] = {0,0,1,-1,1,-1,-1,1};

int homeCnt;

map<pair<int, int>, int > visited;


bool can;
void dfs(pair<int,int> loc, pair<int,int> curEnergy, int cnt, int k)
{
	if(cnt==homeCnt)
	{
		can=true;
		return;
	}
	
	for(int i=0; i<8; i++)
	{
		int nx = loc.first + dx[i];
		int ny = loc.second + dy[i];
		pair<int, int> next = make_pair(nx,ny);
		
			
		if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
		
		//if(k==5 && i==4 && loc.first==0 && loc.second==0)
			//printf("%d %d %d\n",nx,ny, visited[{nx,ny}]);
			
		if(!visited[next])
		{
			pair<int, int> newEnergy = make_pair(min(curEnergy.first, energy[nx][ny]), max(curEnergy.second, energy[nx][ny]));
			
		
			if(newEnergy.second - newEnergy.first > k) continue;
			
			//if(k==5/* && loc.first==0 && loc.second==1*/)
				//printf("%d %d %d %d %d %d %d %d %d\n",loc.first, loc.second, nx, ny, cnt, curEnergy.first, curEnergy.second, newEnergy.first, newEnergy.second);
			
			
			visited[next]=true;
			
			dfs(next, newEnergy, world[nx][ny]==1?cnt+1:cnt,k);
			
			visited[next]=false;
		}
	}
}

int dfs2(pair<int,int> loc, int minEn, int maxEn)
{
	int en = energy[loc.first][loc.second];
	
	if(visited[loc] || loc.first<0 || loc.first>=N || loc.second<0 || loc.second>=N) return 0;
	if(en < minEn || maxEn < en) return 0;
	
	visited[loc]=true;
	int ret=0;
	
	if(world[loc.first][loc.second]==1) ret++;
	
	for(int i=0; i<8; i++)
	{
		int nx = loc.first + dx[i];
		int ny = loc.second + dy[i];
		pair<int, int> next = make_pair(nx,ny);
		
		ret+=dfs2(next,minEn,maxEn);
	}
	
	return ret;
}

bool bfs(pair<int,int> start, pair<int, int> sEnergy, uint64_t k)
{
	map<pair<int, int>, int > chk;
	queue<pair<pair<int, int>,pair<int,int> > > q;
	q.push({start,sEnergy});
	chk[start]=1;
	int cnt=0;
	int minE=987654321, maxE=0;
	
	while(!q.empty())
	{
		pair<int, int> cur = q.front().first;
		pair<int, int> curEnergy = q.front().second;
		
		q.pop();
		
		for(int i=0; i<8; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			pair<int, int> next = make_pair(nx,ny);
			pair<int, int> newEnergy = make_pair(min(curEnergy.first, energy[nx][ny]), max(curEnergy.second, energy[nx][ny]));
			
			if(nx<0 || nx>=N || ny<0 || ny>=N || chk.count(next) || newEnergy.second - newEnergy.first > k) continue;
			minE=min(minE,newEnergy.first);
			maxE=max(maxE,newEnergy.second);
			//if(k==4) printf("%d %d %d %d %d %d %d %d\n",cur.first, cur.second, nx, ny, curEnergy.first, curEnergy.second, newEnergy.first, newEnergy.second);
			
			chk[next]=true;
			if(world[nx][ny]==1) cnt++;
			q.push({next,newEnergy});
		}
	}
	
	return (cnt==homeCnt && maxE- minE <= k);
}

int main()
{
	scanf("%d",&N);
	
	for(int i=0; i<N; i++)
	{
		char c[N+2]={0,};
		scanf("%s",c);
		for(int j=0; j<N; j++)
		{
			if(c[j]=='P')
			{
				startPoint=make_pair(i,j);	
				world[i][j]=2;
			}
			else if(c[j]=='K')
			{	
				homeList.push_back(make_pair(i,j));
				world[i][j]=1;
			}
		}
	}
	homeCnt = homeList.size();
	
	vector<uint64_t> ev;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			scanf("%d",&energy[i][j]);
			ev.push_back(energy[i][j]);
		}
	}
	
	
	sort(ev.begin(), ev.end());
	ev.erase(unique(ev.begin(), ev.end()), ev.end());
	pair<int, int> startEnergy = make_pair(energy[startPoint.first][startPoint.second],energy[startPoint.first][startPoint.second]);
	
	uint64_t p2=0, ans=10000000;
	
	for(int p1=0; p1<ev.size(); p1++)
	{
		while(true)
		{
			//can=false;
			visited.clear();
			//visited[startPoint]=true;
			//dfs(startPoint, startEnergy, 0, ev[p1]-ev[p2]);
			
			if(dfs2(startPoint, ev[p2], ev[p1])!=homeCnt)
				break;
			
			ans = min(ans, ev[p1]-ev[p2]);
			p2++;
		}
		
		//printf("%d %d\n",p1,p2);
	}
	/*
	uint64_t ans=1000000;
	uint64_t left=0, right=1000000;
	
	while(left <= right)
	{
		uint64_t mid = (left+right)/2;
	
		//visited.clear();
		bool b = bfs(startPoint, startEnergy, mid);
		
		//can=false;
		//visited.clear();
		//visited[startPoint]=true;
		//dfs(startPoint, startEnergy, 0, mid);
		
		if(b)
		{
			//printf("%d %d %d\n",left,right,mid);
			right = mid-1;
			//printf("%d %d %d\n",left,right,mid);
			ans=min(ans,mid);
		}
		else left = mid+1;
	}*/
	
	printf("%d",ans);
	//printf("> %d",bfs(startPoint,startEnergy,ans));
	
	return 0;
}
