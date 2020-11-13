#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	
	int N;
	scanf("%d",&N);
	
	vector<pair<long long, long long> > v;
	
	for(int i=0; i<N; i++)
	{
		long long x,y;
		scanf("%lld %lld",&x,&y);
		
		v.push_back({x,y});
	}
	
	sort(v.begin(),v.end());
	
	vector<int> vv;
	for(int i=0; i<N; i++)
	{
		if(i)
		{
			while(vv.size())
			{
				pair<long long,long long> vvMax = v[vv.back()];
				pair<long long,long long> cur = v[i];
				
				if(vvMax.second < cur.second) vv.pop_back();
				else break;
			}
		}
		vv.push_back(i);
	}
	
	
	int size = vv.size();
	long long ans=v[vv[0]].first * v[vv[0]].second;;
	for(int i=1; i<size; i++)
	{
		ans+=(v[vv[i]].first - v[vv[i-1]].first) * v[vv[i]].second;
	}
	
	printf("%lld",ans);
	
	return 0;
}
