#include <stdio.h>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int N,M,S,T;
vector<int> edge[10005], edge_r[10005];
vector<vector<int> > SCC;
vector<int> prt;
vector<vector<int>> SCCGraph;
vector<int> indegree;

void makeSCC(){
	vector<int> stack;
	unordered_map<int, bool> chk;
	auto dfs1 = [&](int idx, auto func) -> void{
		for(int nx: edge[idx]){
			if(!chk.count(nx)){
				chk[nx]=true;
				func(nx,func);
			}
		}
		stack.push_back(idx);
	};
	
	auto dfs2 = [&](int idx, auto func) -> void{
		for(int nx:edge_r[idx]){
			if(!chk.count(nx)){
				chk[nx]=true;
				func(nx,func);
			}
		}
		SCC.back().push_back(idx);
		prt[idx] = SCC.size() - 1;
	};
	
	for(int i=1;i<=N;i++){
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
	
	map<pair<int, int>, bool> chk2;
	
	for(int i=1;i<=N;i++){
		for(int nx : edge[i]){
			if(prt[i] != prt[nx] && !chk2.count({prt[i], prt[nx]})){
				chk2[{prt[i], prt[nx]}] = true;
				SCCGraph[prt[i]].push_back(prt[nx]);
				indegree[prt[nx]]++;
			}
		}
	}
}

int bfs(int S, int T){
	queue<int> q;
	unordered_map<int, bool> chk; //S에서 갈수잇는곳인가 ? 
	vector<int> v(N+5,0);
	
	for(int i=0;i<=N;i++){
		if(!indegree[i]){
			q.push(i);
		}	
	}
	
	v[S] = SCC[S].size();
	chk[S] = true;
	
	while(!q.empty()){
		int frt = q.front(); q.pop();
		for(int nx : SCCGraph[frt]){
			if(chk[frt]){
				v[nx] = max(v[nx], v[frt] + (int)SCC[nx].size());
				chk[nx] = true;
			}
			
			if(!(--indegree[nx])){
				q.push(nx);
			}
		}
	}
	
	return v[T];
}
int main() {
	scanf("%d %d %d %d",&N,&M,&S,&T);
	for(int i=0;i<M;i++){
		int A,B;
		scanf("%d %d",&A,&B);
		edge[A].push_back(B);
		edge_r[B].push_back(A);
	}
	
	indegree = vector<int>(N+5, 0);
	prt = vector<int>(N+5, -1);
	SCCGraph = vector<vector<int>>(N+5, vector<int>());
	
	makeSCC();
	
	printf("%d",bfs(prt[S],prt[T]));
	
	return 0;
}
