#include <stdio.h>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
	while(true){
		int N;
		scanf("%d",&N); if(!N) break;
		vector<vector<int>> edge = vector<vector<int>>(30, vector<int>());
		vector<vector<int>> edge_r = vector<vector<int>>(30, vector<int>());
		vector<vector<int>> SCC;
		unordered_map<int, bool> m;
		while(N--){
			char arr[5]={0,};
			for(int i=0;i<5;i++){
				scanf(" %c",arr + i);
			}
			
			char c;
			scanf(" %c",&c);
			
			for(int i=0;i<5;i++){
				edge[c-'A'].push_back(arr[i]-'A');
				edge_r[arr[i]-'A'].push_back(c-'A');
				m[arr[i]-'A'] = true;
			}
			m[c-'A']=true;
		}
		
		unordered_map<int, bool> chk;
		vector<int> st;
		auto dfs1 = [&](int idx, auto func) -> void{
			for(int nx : edge[idx]){
				if(!chk.count(nx)){
					chk[nx]=true;
					func(nx, func);
				}
			}
			st.push_back(idx);
		};
		for(int i=0;i<26;i++){
			if(!chk.count(i) && m[i]==true){
				chk[i]=true;
				dfs1(i, dfs1);
			}
		}
		chk.clear();
		auto dfs2 = [&](int idx, auto func) -> void{
			for(int nx : edge_r[idx]){
				if(!chk.count(nx)){
					chk[nx]=true;
					func(nx, func);
				}
			}
			SCC.back().push_back(idx);
		};
		for(int i=st.size()-1;i>=0;i--){
			if(!chk.count(st[i])){
				chk[st[i]]=true;
				SCC.push_back(vector<int>());
				dfs2(st[i], dfs2);
				sort(SCC.back().begin(), SCC.back().end());
			}
		}
		sort(SCC.begin(), SCC.end());
		for(vector<int> compo : SCC){
			for(int a : compo){
					printf("%c ",a+'A');
				}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
