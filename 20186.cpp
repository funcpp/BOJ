#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	vector<int> v;
	for(int i=0;i<N;i++)
	{
		v.push_back(0);
		scanf("%d",&v.back());
	}
	sort(v.begin(), v.end());
	long long int ans = 0;
	for(auto it = v.end()-1;it>=v.end()-K;it--){
		ans+=*it;
	}
	printf("%lld",ans-(K*(K-1)/2));
	
	return 0;
}
