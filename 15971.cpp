#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int N,A,B;
vector<pair<long long, int> > edge[100005];

void dijkstra(int S, vector<long long>& v) {
	v = vector<long long>(N+5, 0x7f7f7f7f);
	
	priority_queue<pair<long long, int> > pq;
	pq.push({0,S});
	v[S]=0;
	
	while(!pq.empty()) {
		int x = pq.top().second;
		int c = -pq.top().first;
		pq.pop();
		
		if(v[x] < c) continue;
		
		for(pair<long long, int> np : edge[x]){
			long long nc = c + np.second;
			int nx = np.first;
			
			if(nc < v[nx]){
				v[nx]=nc;
				pq.push({-nc, nx});
			}
		}
	}
}

int main() {
	scanf("%d %d %d",&N,&A,&B);
	
	if(N==1 || A==B){
		printf("0");
		return 0;
	}
	
	for(int i=1;i<N; i++){
		int q,w,e;
		scanf("%d %d %d",&q,&w,&e);
		edge[q].push_back({w, e});
		edge[w].push_back({q, e});
	}
	
	vector<long long> v1;
	vector<long long> v2;
	
	dijkstra(A,v1);
	dijkstra(B,v2);
	long long ans = 0x7f7f7f7f;
	
	for(int i=1; i<=N; i++) {
		for(pair<int, int> j : edge[i]){
			if(v1[i] + v2[j.first] < ans) {
				ans = v1[i] + v2[j.first];
			}
		}
	}
	printf("%d",ans);
	return 0;
}
