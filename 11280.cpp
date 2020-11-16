#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int N,M;

#define notX(x) (x^1)
#define trueX(x) (x<<1)
#define falseX(x) (x<<1|1)

vector<vector<int>> edge, redge, SCC;
vector<int> SCCN;

void makeSCC()
{
	unordered_map<int ,bool> chk;
	vector<int> st;
	auto dfs1 = [&](int idx, auto func)->void{
		for(int nx : edge[idx]){
			if(!chk.count(nx)){
				chk[nx]=true;
				func(nx, func);
			}
		}
		st.push_back(idx);
	};
	
	auto dfs2 = [&](int idx, auto func)->void{
		for(int nx : redge[idx]){
			if(!chk.count(nx)){
				chk[nx]=true;
				func(nx, func);
			}
		}
		SCC.back().push_back(idx);
		SCCN[idx] = SCC.size()-1;
	};
	
	for(int i=2;i<=N*2+1;i++){
		if(!chk.count(i)){
			chk[i]=true;
			dfs1(i,dfs1);
		}
	}
	
	chk.clear();
	
	for(int i=st.size()-1;i>=0;i--){
		if(!chk.count(st[i])){
			chk[st[i]]=true;
			SCC.push_back(vector<int>());
			dfs2(st[i],dfs2);
		}
	}
}

int main()
{
	scanf("%d %d",&N,&M); 
	edge = vector<vector<int>>(N+1<<1, vector<int>());
	redge = vector<vector<int>>(N+1<<1, vector<int>());
	SCCN = vector<int>(N+1<<1,-1);
	
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		
		a = a>0 ? trueX(a) : falseX(-a);
		b = b>0 ? trueX(b) : falseX(-b);
		
		edge[notX(a)].push_back(b);
		edge[notX(b)].push_back(a);	
		
		redge[a].push_back(notX(b));
		redge[b].push_back(notX(a));
	}

	makeSCC();
	
	for(int i=1;i<=N;i++){
		if(SCCN[trueX(i)] == SCCN[falseX(i)]){
			printf("0");
			return 0;
		}
	}
	printf("1");
	
	return 0;
}
