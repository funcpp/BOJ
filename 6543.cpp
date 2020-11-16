#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int N,M;
vector<vector<int>> edge, edge_r;
vector<vector<int>> SCC;
vector<int> ansNode;
vector<int> SCCN;

void makeSCC()
{
	vector<int> stack;
	unordered_map<int, bool> chk;
	
	auto dfs1 = [&](int idx, auto func) -> void{		
		for(int nx : edge[idx]){
			if(!chk.count(nx)){
				chk[nx] = true;
				func(nx, func);
			}
		}
		stack.push_back(idx);
	};
	
	auto dfs2 = [&](int idx, auto func) -> void{		
		for(int nx : edge_r[idx]){
			if(!chk.count(nx)){
				chk[nx] = true;
				func(nx, func);
			}
		}
		SCC.back().push_back(idx);
		SCCN[idx] = SCC.size()-1;
	};
	
	for(int i=1; i<=N; i++){
		if(!chk.count(i)){
			chk[i]=true;
			dfs1(i, dfs1);
		}
	}
	
	chk.clear();
	
	for(int i=stack.size()-1; i>=0; i--){
		if(!chk.count(stack[i])){
			chk[stack[i]]=true;
			SCC.push_back(vector<int>());
			dfs2(stack[i], dfs2);
		}
	}
	
	return;
}

int main(){
	while(1){
	
		edge.clear();
		edge_r.clear();
		SCC.clear();
		ansNode.clear();
		
		scanf("%d",&N);
		if(!N) break;
		scanf("%d",&M);
		
		edge = vector<vector<int>>(N+5, vector<int>());
		edge_r = vector<vector<int>>(N+5, vector<int>());
		SCCN = vector<int>(N+5,-1);
		
		for(int i=0;i<M;i++){
			int A,B;
			scanf("%d %d",&A,&B);
			
			edge[A].push_back(B);
			edge_r[B].push_back(A);
		}
		
		makeSCC();
		
		vector<vector<int> > SCCGraph = vector<vector<int>>(N+5,vector<int>());
		map<pair<int, int>, bool> chk;
		
		for(int i=1;i<=N;i++){
			for(int j : edge[i]){
				if(SCCN[i] != SCCN[j] && !chk.count({SCCN[i], SCCN[j]})){
					chk[{SCCN[i], SCCN[j]}] = true;
					SCCGraph[SCCN[i]].push_back(SCCN[j]);	
				}
			}
		}
		
		for(int i=1; i<=N; i++){
			if(SCCGraph[SCCN[i]].size() == 0){
				printf("%d ",i);
			}
		}
		printf("\n");
	}
}
