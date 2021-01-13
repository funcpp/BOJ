#include<bits/stdc++.h>
using namespace std;

int N;
long long int cnt[300005];
long long int ans;
vector<vector<int> > edge;
unordered_map<int, bool> chk;
long long int f(int idx)
{
	
	long long int & ret = cnt[idx] = 1;
	for(int nx : edge[idx])
	{
		if(!cnt[nx])
		{
			ret += f(nx);
		}
	}
	
	if(idx!=1)
		ans += (1LL * (N)*(N-1)/2) - (1LL * (N-ret)*(N-ret-1)/2);
	
	return ret;
}

	
int main()
{
	scanf("%d", &N);
	
	edge = vector<vector<int>>(N+5,vector<int>());
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	f(1);
	printf("%d",ans);
	
	return 0;
}
