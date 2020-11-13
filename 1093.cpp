#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

long long N,K;
pair<int,int> arr[35];
long long stCnt,st;
long long half;

vector<pair<long,long> > v1,v2;

void dfs(int idx, long money, long c)
{
	if(idx==half)
	{
		v1.push_back({money,c});
		return;
	}
	
	dfs(idx+1,money,c);
	dfs(idx+1,money+arr[idx].first,c+arr[idx].second);
}

void dfs2(int idx, long money, long c)
{
	if(idx==N)
	{
		v2.push_back({money,c});
		return;
	}
	
	dfs2(idx+1,money,c);
	dfs2(idx+1,money+arr[idx].first,c+arr[idx].second);
}

int main()
{
	scanf("%lld",&N);
	half = N / 2;
	
	for(int i=0; i<N; i++)
		scanf("%lld",&arr[i].first);
		
	for(int i=0; i<N; i++)
		scanf("%lld",&arr[i].second);
		
	scanf("%lld",&K);
	scanf("%lld",&stCnt);
	
	for(int i=0; i<stCnt; i++)
	{
		int n;
		scanf("%d",&n);
		st+=arr[n-1].second;
		arr[n-1]={0,0};
	}
	
	dfs(0,0,0);
	dfs2(half,0,0);
	
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	
	/*
	for(auto i : v1)
	{
		printf("%d %d\n",i.first,i.second);
	}
	
	for(auto i : v2)
	{
		printf("%d %d\n",i.first,i.second);
	}*/
	
	vector<pair<int, int> > ans;
	
	int t =  v2.size()-1;
	for(auto i : v1)
	{
		while(t && i.second + v2[t].second + st >= K)
		{
			ans.push_back({i.first+v2[t].first, i.second + v2[t].second + st});
			t--;
		}
	}
	
	if(ans.size())
	{
		sort(ans.begin(),ans.end());
		printf("%d",ans[0].first);
	}
	else
	{
		printf("-1");
	}
	return 0;
}
