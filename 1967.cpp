#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector<pii> tree[10005];

int ans = 0;

int f(int idx)
{
	vector<int> v;
	for(pii p : tree[idx])
	{
		if(tree[p.first].size())
		{
			v.push_back(p.second + f(p.first));
		}
		else
		{
			v.push_back(p.second);
		}
	}
	sort(v.begin(),v.end());
	ans = max(ans, v[v.size()-1] + v[v.size()-2]);
	
	return v.back();
}

int main()
{
	int n;
	scanf("%d",&n);
	n--;
	while(n--)
	{
		int p,c,w;
		scanf("%d %d %d",&p,&c,&w);
		tree[p].push_back({c,w});
	}
	
	f(1);
	
	printf("%d",ans);
}
