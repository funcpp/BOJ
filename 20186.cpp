#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	
	vector<int> v;
	for(int i=0,t;i<N;i++){
		scanf("%d",&t);
		v.push_back(t);
	}
	
	sort(v.begin(), v.end());
	
	long long int ans = 0;
	for(auto it=v.end()-1;it>=v.end()-K;it--){
		ans+=*it;
	}
	long long int sub = 1LL * (K) * (K-1) / 2;
	printf("%lld\n",ans-sub);
}
