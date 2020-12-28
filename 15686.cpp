#include<bits/stdc++.h>
using namespace std;
#define u64 long long int
int N,M;
int arr[55][55];
vector<u64> ck;
vector<u64> hm;

u64 getd(u64 a, u64 b)
{
	return abs((a>>16) - (b>>16)) + abs((a&0xFFFF) - (b&0xFFFF));
}

u64 ans = 0x7f7f7f7f;
void dfs(vector<int> se, int idx){
	if(idx==ck.size()+1) return;
	
	if(se.size()==M){
		u64 _ans = 0;
		for(u64 _hm:hm){
			u64 _v=0x7f7f7f7f;
			for(int _idx:se){
				_v=min(_v,getd(_hm,ck[_idx]));
			}
			_ans+=_v;
		}
		ans=min(ans,_ans);
		return;
	}
	
	se.push_back(idx);
	dfs(se, idx+1);
	
	se.pop_back();
	dfs(se,idx+1);
}
 
int main()
{
	scanf("%d %d",&N,&M);
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==1){
				hm.push_back(0);
				hm.back()=(i<<16)+j;
			}
			else if(arr[i][j]==2){
				ck.push_back(0);
				ck.back()=(i<<16)+j;
			}
		}
	}
	
	dfs(vector<int>(),0);
	printf("%lld",ans);
	
	return 0;
}
