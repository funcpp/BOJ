#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	int T,N,t;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		
		vector<vector<int>> arr = vector<vector<int>>(N+5,vector<int>(N+5,0));
		vector<vector<int>> edge = vector<vector<int>>(N+5,vector<int>());
		vector<vector<int>> edge_r = vector<vector<int>>(N+5,vector<int>());
		vector<vector<int>> SCCGraph = vector<vector<int>>(N+5,vector<int>());
		vector<vector<int>> SCC;
		
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				scanf("%1d",&t);
				if(t && i!=j){
					edge[i].push_back(j);
					edge_r[j].push_back(i);
				}
				arr[i][j]=t;
			}
		}
		
		vector<int> st;
		unordered_map<int, bool> chk;
		vector<int> SCCN = vector<int>(N+5, -1);
		
		auto dfs1 = [&](int idx, auto func) -> void{
			for(int nx : edge[idx]){
				if(!chk.count(nx)){
					chk[nx]=true;
					func(nx, func);
				}
			}
			st.push_back(idx);
		};
		
		auto dfs2 = [&](int idx, auto func) -> void{
			for(int nx : edge_r[idx]){
				if(!chk.count(nx)){
					chk[nx]=true;
					func(nx, func);
				}
			}
			SCC.back().push_back(idx);
			SCCN[idx] = SCC.size()-1;
		};
		
		for(int i=1;i<=N;i++){
			if(!chk.count(i)){
				chk[i]=true;
				dfs1(i,dfs1);
			}
		}
		chk.clear();
		for(int i=st.size()-1; i>=0; i--){
			if(!chk.count(st[i])){
				SCC.push_back(vector<int>());
				chk[st[i]]=true;
				dfs2(st[i], dfs2);
			}
		}
		
		map<pair<int, int>, bool> chk2;
		vector<pair<int, int>> ans;
		for(int i=st.size()-1;i>=0; i--){
			for(int j=i-1;j>=0;j--){
				int u=st[i],v=st[j];
				
				if(SCCN[u]!=SCCN[v] && !chk2.count({SCCN[u], SCCN[v]}) && arr[u][v]){
					bool need = true;
					for(int k=i-1; k>=j+1; k--){
						int w = st[k];
						if(arr[u][w] && arr[w][v]){
							need=false;
							break;
						}
					}
					if(need){
						ans.push_back({u,v});
						chk2[{SCCN[u], SCCN[v]}] = true;
					}
				}
			}
		}
		
		for(vector<int> compo : SCC){
			int u = compo[compo.size()-1];
			for(auto it = compo.begin(); it!=compo.end();it++){
				if(u!=*it) ans.push_back({u, *it});
				u=*it;
			}
		}
		
		printf("%d\n",ans.size());
		for(auto pii : ans){
			printf("%d %d\n",pii.first, pii.second);
		}
	}
	return 0;
}
