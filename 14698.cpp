#include <bits/stdc++.h>
#define ull unsigned long long int
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		priority_queue<ull, vector<ull>, greater<ull>> pq;
		int N;
		scanf("%d",&N);
		
		for(int i=0;i<N;i++){
			ull t;
			scanf("%llu",&t);
			
			pq.push(t);
		}
		
		ull ans = 1;
		long long int mod = 1e9+7;
		
		while(pq.size()>=2) {
			ull a = pq.top(); pq.pop();
			a*= pq.top(); pq.pop();
			ans = ans * (a%mod) %mod;
			//printf("%llu\n",a%mod);
			pq.push(a);
		}
		
		printf("%llu\n",ans);
	}
	return 0;
}
