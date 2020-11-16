#include <stdio.h>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
#include <stdlib.h>
#define ull unsigned long long
#define inf 1000000001

using namespace std;

ull fnDist(int a, pair<int,int> b)
{
	int t = abs(a-b.first);
	
	return t+b.second;
}

int main()
{
	int M,N,L;
	
	scanf("%d %d %d",&M,&N,&L);
	
	vector<int> sd;
	vector<pair<int, int> > pos;
	map<pair<int, int>, bool > m;
	
	for(int i=0; i<M; i++)
	{
		int t;
		scanf("%d",&t);
		sd.push_back(t);
	}
	
	for(int i=0; i<N; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		pos.push_back({x,y});
	}
	
	sort(sd.begin(), sd.end());
	sort(pos.begin(), pos.end());
	
	int lastIdx=0;
	int ans=0;
	
	for(int i=0; i<N; i++)
	{
		while(lastIdx!=M-1 && sd[lastIdx+1] < pos[i].first)
		{
			lastIdx++;
		}
		
		if(fnDist(sd[lastIdx],pos[i]) <= L || (lastIdx!=M-1 && fnDist(sd[lastIdx+1], pos[i]) <= L))
		{
			ans++;
		}
	}
	
	printf("%d",ans);
	
	return 0;
}
