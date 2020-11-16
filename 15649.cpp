#include <bits/stdc++.h>
using namespace std;

int N,M;

vector<vector<int>> v;
void f(int idx, vector<int> vv)
{
	if(vv.size()==M){
		v.push_back(vv);
		return;
	}
	if(idx==N+1) return;
		
	vv.push_back(idx);
	f(idx+1, vv);
	vv.pop_back();
	f(idx+1, vv);
	
}

int main()
{
	scanf("%d %d",&N,&M);
	
	f(1, vector<int>());
	
	vector<vector<int>> ans;
	for(vector<int> s : v)
	{
		do{
			ans.push_back(s);
		}while(next_permutation(s.begin(), s.end()));
	}
	sort(ans.begin(), ans.end());
	for(auto a : ans){
		for(int i :a){
			printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}
