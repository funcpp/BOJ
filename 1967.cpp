#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int N;
#define pii pair<int, int>
vector<vector<pii>> edge;
int ans;
int dfs(int idx){
	vector<int> v;
	for(auto nn : edge[idx]){
		if(edge[nn.first].size()) {
			v.push_back(nn.second + dfs(nn.first));
		}
		else {
			v.push_back(nn.second);
		}
	}
	sort(v.begin(), v.end());
	if(edge[idx].size()>=2){
		ans = max(ans, v[v.size()-1] + v[v.size()-2]);
	}
	return v.back();
}

int main()
{
	scanf("%d",&N);
	edge=vector<vector<pii>>(N+5, vector<pii>());
	edge[0].push_back({1,0});
	for(int i=0;i<N-1;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		edge[u].push_back({v,w});
	}
	
	ans = max(ans,dfs(0));
	printf("%d",ans);
	return 0;
}
