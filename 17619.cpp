#include<bits/stdc++.h>
using namespace std;

struct ddang
{
	pair<int, int> pos;	
	int idx;
};

int main()
{
	int N,Q;
	scanf("%d %d",&N,&Q);
	vector<ddang> v;
	for(int i=0;i<N;i++)
	{
		int x1,x2,y;
		ddang d;
		scanf("%d %d %d",&x1,&x2,&y);
		d.pos={x1,x2};
		d.idx=i;
		v.push_back(d);
	}
	
	sort(v.begin(), v.end(), [&](ddang a, ddang b) -> bool{return a.pos<b.pos;});
	
	int prt[N+5]={0,};
	prt[v[0].idx]=1;
	int right = v[0].pos.second;
	for(int i=1;i<N;i++)
	{
		if(v[i].pos.first <= right)
		{
			right = max(right, v[i].pos.second);
			prt[v[i].idx]=prt[v[i-1].idx];
		}
		else
		{
			right=v[i].pos.second;
			prt[v[i].idx]=prt[v[i-1].idx]+1;
		}
	}
	
	for(int i=0;i<Q;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		
		if(prt[a-1]&&prt[b-1]&&prt[a-1]==prt[b-1]) printf("1\n");
		else printf("0\n");
		
	}
	
	return 0;
}
