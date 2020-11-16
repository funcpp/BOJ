#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

#define trueX(x) (x<<1)
#define falseX(x) (x<<1|1)
#define notX(x) (x^1)

int N,M;
vector<vector<int>> edge, redge, SCC;
vector<int> SCCN;

void makeSCC()
{
	unordered_map<int, bool> chk;
	vector<int> st;
	auto dfs1 = [&](int idx, auto func)->void{
		for(int nx : edge[idx]){
			if(!chk.count(nx)){
				chk[nx]=true;
				func(nx,func);
			}
		}
		st.push_back(idx);
	};
	auto dfs2 = [&](int idx, auto func)->void{
		for(int nx : redge[idx]){
			if(!chk.count(nx)){
				chk[nx]=true;
				func(nx,func);
			}
		}
		SCC.back().push_back(idx);
		SCCN[idx] = SCC.size()-1;
	};
	for(int i=2; i<=2*N+1; i++){
		if(!chk.count(i)){
			chk[i]=true;
			dfs1(i,dfs1);
		}
	}
	chk.clear();
	for(int i=st.size()-1; i>=0;i--){
		if(!chk.count(st[i])){
			chk[st[i]]=true;
			SCC.push_back(vector<int>());
			dfs2(st[i],dfs2);
		}
	}
}

int main(){
	while(~scanf("%d %d",&N,&M)){
		edge = vector<vector<int>>(N+1<<1, vector<int>());
		redge = vector<vector<int>>(N+1<<1, vector<int>());
		SCCN =  vector<int>(N+1<<1, 0);
		SCC.clear();
		
		for(int i=0;i<M;i++){
			int a, b;
			scanf("%d %d",&a,&b);
			a = a>0 ? trueX(a) : falseX(-a);
			b = b>0 ? trueX(b) : falseX(-b);
			
			edge[notX(a)].push_back(b);
			edge[notX(b)].push_back(a);
			
			redge[a].push_back(notX(b));
			redge[b].push_back(notX(a));	
		}
		
		makeSCC();
		
		bool b = true;
		for(int i=1;i<=N;i++){
			if(SCCN[trueX(i)] == SCCN[falseX(i)]){
				b=false;
				break;
			}
		}
		printf("%s\n", b ?  "1" : "0");
	}
}
