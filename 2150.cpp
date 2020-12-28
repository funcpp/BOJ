#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > edge, redge;
int main()
{
	int V,E;
	scanf("%d %d",&V,&E);
	
	edge = vector<vector<int> >(V+5, vector<int>());
	redge = vector<vector<int> >(V+5, vector<int>());
		
	for(int i=0;i<E;i++){
		int A,B;
		scanf("%d %d",&A,&B);
		
		edge[A].push_back(B);
		redge[B].push_back(A);
	}
	
	unordered_map<int, bool> chk;
	vector<int> st;
	auto dfs = [&](int idx, auto dfs) -> void
	{
		for(int nx : edge[idx])
		{
			if(!chk.count(nx)){
				chk[nx]=true;
				dfs(nx,dfs);
			}
		}
		st.push_back(idx);
	};
	
	vector<vector<int> > SCC;
	auto rdfs = [&](int idx, auto rdfs) -> void
	{
		for(int nx : redge[idx])
		{
			if(!chk.count(nx)){
				chk[nx]=true;
				rdfs(nx,rdfs);
			}
		}
		SCC.back().push_back(idx);
	};
	
	
	for(int i=1;i<=V;i++){
		if(!chk.count(i))
		{
			chk[i]=true;
			dfs(i,dfs);
		}
	}
	
	chk.clear();
	for(int i=st.size()-1;i>=0;i--){
		if(!chk.count(st[i]))
		{
			SCC.push_back(vector<int>());
			chk[st[i]]=true;
			rdfs(st[i], rdfs);
			sort(SCC.back().begin(), SCC.back().end());
		}
	}
	
	printf("%d\n",SCC.size());
	sort(SCC.begin(), SCC.end());
	for(auto compo : SCC){
		for(int i : compo){
			printf("%d ",i);
		}
		printf("-1\n");
	}
	return 0;
}
