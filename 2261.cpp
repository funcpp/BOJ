#include <stdio.h>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

#define ull unsigned long long
#define inf 1e10

using namespace std;

ull fnDist(pair<int,int> a, pair<int,int> b)
{
	ull dx = a.first - b.first;
	ull dy = a.second - b.second;
	
	return dx*dx + dy*dy;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	vector<pair<int,int> > pos;
	map<pair<int,int>, bool> m;
	
	for(int i=0; i<n; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		
		pos.push_back({x,y});
	}
	
	m[{pos[0].y, pos[0].x}]=true;
	m[{pos[1].y, pos[1].x}]=true;
	ull ans=fnDist(pos[0],pos[1]);
	int lastIdx=0;
	
	for(int i=2; i<n; i++)
	{
		while(lastIdx < i)
		{
			ull dx = pos[i].first - pos[lastIdx].first;
			if(dx*dx <= ans) break;
			
			m.erase({pos[lastIdx].second, pos[lasIdx].first});
			
			lastIdx++;
		}
		
		m[{pos[lastIdx].second, pos[lastIdx].first}]=true;
		
		double d = sqrt(ans);
		
		auto upp = m.upper_bound({pos[i].second + d, inf});
		auto low = m.lower_bound({pos[i].second - d, -inf});
		
		for(auto it = low; it!=upp; it++)
		{
			ull t = fnDist(pos[i], {it->first.second, it->first.first});
			ans = min(t,ans);
		}
	}
	
	printf("%llu",ans);
}
