#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	
	vector<pair<int,int> > v;
	map<int, bool> m[N+1];
	map<int, bool> m2[N+1];
	for(int i=0; i<N; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		v.push_back({x,y});
		m[y][x]=true;
		m2[y][-x]=true;
	}
	
	
	unsigned long long ans = 0;
	
	for(int i=0; i<N; i++)
	{
		auto upp = m[v[i].second].upper_bound(v[i].first);
		auto upp2 = m2[v[i].second].upper_bound(-v[i].first);
		
		if(!upp->second && !upp2->second)
			continue;
		if(!upp->second)
			ans+=abs(v[i].first+upp2->first);
		else if(!upp2->second)
			ans+=abs(v[i].first-upp->first);
		else
			ans+=min(abs(v[i].first-upp->first),abs(v[i].first+upp2->first));
		//printf("%d %d %d %d %d %d\n",v[i].first, upp->first, upp->second, -upp2->first, upp2->second, ans);
	}
	
	printf("%llu",ans);
	return 0;
}
