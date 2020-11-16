#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int N,K;
int dx[2] = {1,-1};
int main()
{
	scanf("%d %d",&N,&K);
	
	priority_queue<pair<int, int> > pq;
	pq.push({0,N});
	
	vector<int> ans = vector<int>(100005, 0x7f7f7f7f);
	ans[N] = 0;
	
	while(!pq.empty()){
		pii top = pq.top(); pq.pop();
		int cost = -top.first;
		if(cost > ans[top.second]) continue;
		
		for(int i=0;i<2;i++){
			int nx  = top.second+dx[i];
			if(nx>=0 && nx<=100000) {
				if(cost+1 < ans[nx]){
					ans[nx]=cost+1;
					pq.push({-(cost+1), nx});
				}
			}
		}
		
		int nx = top.second*2;
		if(nx>=0 && nx<=100000) {
			if(cost < ans[nx]){
				ans[nx]=cost;
				pq.push({-cost, nx});
			}
		}
	}
	
	printf("%d",ans[K]);

	return 0;
}
