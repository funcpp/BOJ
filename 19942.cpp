#include <bits/stdc++.h>
using namespace std;
int N, m[4];

struct st
{
	int a,b,c,d,s;
	st()
	{
		a=0,b=0,c=0,d=0,s=0;
	}
	st(int A, int B, int C, int D, int S) : a(A), b(B), c(C), d(D), s(S) {};
	
	st operator+(const struct st& v){
		return st(this->a+v.a, this->b+v.b, this->c+v.c,this->d+v.d,this->s+v.s);
	}
	
};

st s[0x10];
int mCost = 0x7f7f7f7f;
vector<vector<int>> ans;

void f(int idx, vector<int> selected, st cur)
{
	if(cur.a>=m[0]&&cur.b>=m[1]&&cur.c>=m[2]&&cur.d>=m[3])
	{
		if(cur.s == mCost) {
			ans.push_back(selected);
		}
		else if(cur.s < mCost){
			mCost=cur.s;
			ans.clear();
			ans.push_back(selected);
		}
		return;
	}
	if(idx==N) return;
	
	selected.push_back(idx);
	f(idx+1,selected,cur+s[idx]);
	selected.pop_back();
	f(idx+1,selected,cur);
}



int main()
{
	scanf("%d",&N);
	for(auto it=m;it!=m+4;it++){
		scanf("%d",it);
	}
	
	for(int i=0;i<N;i++){
		scanf("%d %d %d %d %d",&s[i].a,&s[i].b,&s[i].c,&s[i].d,&s[i].s);
	}
	
	f(0,vector<int>(), st());
	
	if(ans.size()){
		sort(ans.begin(),ans.end());
		printf("%d\n",mCost);
		for(int p : ans[0]){
			printf("%d ",p+1);
		}
	}else{
		printf("-1");
	}
	return 0;
}
