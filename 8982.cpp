#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int main()
{
	int N,K;
	scanf("%d",&N);
	
	vector<pii> v;
	
	for(int i=0,a,b;i<N;i++){
		scanf("%d %d",&a,&b);
		v.push_back({a,b});
	}
	
	sort(v.begin(), v.end());
	
	vector<pii> vv(N*2);
	for(int i=1;i<N;){
		if(v[i].second!=v[i-1].second)
		{
			vv[i].first
		}
	}
	
	scanf("%d",&K);
	for(int i=0,a,b;i<K;i++){
		scanf("%d %d",&a,&b);
	}
	return 0;
}
