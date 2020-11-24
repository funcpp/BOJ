 #include<bits/stdc++.h>
using namespace std;

#define INF 0x7f7f7f7f

vector<vector<int>> SCC;
vector<vector<int>> edge, redge;
vector<int> cost, sccid;

int main() {
	int N;
	scanf("%d",&N);
	cost = vector<int>(N, 0);
	sccid = vector<int>(N+5,-1);
	edge = vector<vector<int>>(N+5, vector<int>());
	redge = vector<vector<int>>(N+5, vector<int>());
	
	for(int i=0;i<N;i++){
		scanf("%d",&cost[i]);
	}
	
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		
		for(int j=0;j<N;j++){
			if(s[j]=='Y'){
				edge[i].push_back(j);
				redge[j].push_back(i);
			}
		}
	}
	
	unordered_map<int, bool> chk;
	vector<int> st;
	auto dfs1 = [&](int idx, auto func)->void{
		for(int nx : edge[idx]){
			if(!chk.count(nx)){
				chk[nx]=true;
				func(nx, func);
			}
		}
		st.push_back(idx);
		return;
	};
	
	auto dfs2 = [&](int idx, auto func)->void{
		for(int nx : redge[idx]){
			if(!chk.count(nx)){
				chk[nx]=true;
				func(nx, func);
			}
		}
		SCC.back().push_back(idx);
		sccid[idx]=SCC.size()-1;
		return;
	};
	
	for(int i=0;i<N;i++){
		if(!chk.count(i)){
			chk[i]=true;
			dfs1(i, dfs1);
		}
	}
	
	chk.clear();
	
	for(auto it=st.end()-1;it>=st.begin();it--) {
		if(!chk.count(*it)){
			SCC.push_back(vector<int>());
			chk[*it]=true;
			dfs2(*it, dfs2);
		}
	}
	
	vector<int> ind = vector<int>(N+5,0);
	
	for(int x=0;x<N;x++){
		for(int nx : edge[x]){
			if(sccid[x] != sccid[nx]){
				ind[sccid[nx]]++;
			}
		}
	}
	
	double ans=0;
	int cnt=0;
	
	for(int i=0;i<SCC.size();i++){
		if(!ind[i]){
			auto compo = SCC[i];
			int* co = NULL;
			for(int x : compo){
				if(co==NULL || cost[x] <= *co){
					co=&cost[x];
				}
			}
			ans+=*co;
			cnt++;
			*co=INF;
		}
	}
	
	sort(cost.begin(), cost.end());
	
	for(int i=0;i<N;i++){
		if(cost[i]!=INF){
			if((double)(ans+cost[i])/(cnt+1) < (double)(ans/cnt)){
				ans+=cost[i];
				cnt++;
			}
		}
	}
	
	printf("%.11lf",(double)ans/(double)cnt);
	
	return 0;
}
