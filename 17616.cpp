#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> edge,redge;

unordered_map<int,bool> m;
int cnt;
void dfs(int idx, vector<vector<int>>& ed)
{
	for(auto e:ed[idx])
	{
		if(!m.count(e)){
			m[e]=true;
			cnt++;
			dfs(e,ed);
		}
	}
}

int main()
{
	int N,M,X;
	scanf("%d %d %d",&N,&M,&X);
	edge = vector<vector<int>>(N+5,vector<int>());
	redge = vector<vector<int>>(N+5,vector<int>());
	
	for(int i=0;i<M;i++){
		int A,B;
		scanf("%d %d",&A,&B);
		edge[A].push_back(B);
		redge[B].push_back(A);
	}
	
	cnt=0;
	dfs(X,edge);
	int low=N-cnt;
	cnt=0;
	m.clear();	
	dfs(X,redge);
	int high = cnt+1;
	printf("%d %d",high,low);
	return 0;
}
