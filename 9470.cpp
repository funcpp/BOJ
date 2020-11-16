#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;
#define pii pair<int, int>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int K,M,P;
		scanf("%d %d %d",&K,&M,&P);
		vector<vector<int>> edge = vector<vector<int>>(M+5, vector<int>());
		vector<int> ind = vector<int>(M+5, 0);
		while(P--){
			int A,B;
			scanf("%d %d",&A,&B);
			
			edge[A].push_back(B);
			ind[B]++;
		}
		
		vector<pii> ans = vector<pii>(M+5, pii());
		queue<int> q;
		for(int i=1;i<=M;i++){
			if(!ind[i]){
				q.push(i);
				ans[i].first=1;
				ans[i].second=1;
			}
		}
		
		while(q.size()){
			int frt = q.front(); q.pop();
			for(int nx : edge[frt]){
				--ind[nx];
				if(ans[nx].first < ans[frt].first)
				{
					ans[nx].first = ans[frt].first;
					ans[nx].second = 1;
				}
				else if(ans[nx].second ==1 && ans[nx].first == ans[frt].first){
					
					ans[nx].first++;
					ans[nx].second++;
				}
				
				if(!ind[nx]){
					q.push(nx);
				}
			}
		}
		printf("%d %d\n",K,ans[M].first);
	}
	return 0;
}
