#include<bits/stdc++.h>
using namespace std;
int N;
struct comb
{
	int mp,mf,ms,mv, cost;
	
	comb operator +(const struct comb& c)
	{
		return {mp+c.mp,mf+c.mf,ms+c.ms,mv+c.mv,cost+c.cost};
	}
};

int ans_cost=0x7f7f7f7f;
vector<vector<int> >ans;
comb limit;
vector<comb> cbs;
void f(int idx, comb cur, vector<int> a)
{
	if(idx>N) return;
	if(cur.cost>ans_cost)return;
	
	if(cur.mp>=limit.mp&&cur.mf>=limit.mf&&cur.ms>=limit.ms&&cur.mv>=limit.mv)
	{
		if(cur.cost == ans_cost)
		{
			ans.push_back(a);
		}
		else if(cur.cost < ans_cost)
		{
			ans_cost =cur.cost;
			ans.clear();
			ans.push_back(a);
		}
	}
	
	a.push_back(idx);
	f(idx+1,cur+cbs[idx], a);
	a.pop_back();
	f(idx+1,cur, a);
	return;
}

int main()
{
	scanf("%d",&N);
	scanf("%d %d %d %d",&limit.mp,&limit.mf,&limit.ms,&limit.mv);
	
	for(int i=0;i<N;i++)
	{
		comb c;
		scanf("%d %d %d %d %d",&c.mp,&c.mf,&c.ms,&c.mv,&c.cost);
		cbs.push_back(c);
	}
	
	f(0,{0,0,0,0,0}, vector<int>());
	
	if(ans_cost==0x7f7f7f7f)
		printf("-1");
	else
	{
		printf("%d\n",ans_cost);
		sort(ans.begin(), ans.end());
		for(auto b:ans[0])
		{
			printf("%d ",b+1);
		}
	}
	return 0;
}
