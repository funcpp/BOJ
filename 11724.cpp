#include<bits/stdc++.h>
using namespace std;
vector<int> ed[1005];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	
	unordered_map<int,bool> chk;
	auto dfs = [&](int idx, auto dfs) -> void
	{
		for(int nx : ed[idx]){
			if(!chk.count(nx)){
				chk[nx]=true;
				dfs(nx,dfs);
			}
		}
	};
	
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!chk.count(i)){
			chk[i]=true;
			dfs(i,dfs);
			ans++;
		}
	}
	
	printf("%d",ans);
	
	return 0;
}
