#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> v;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		v.push_back(0);
		scanf("%d",&v.back());
	}
	sort(v.begin(), v.end());
	printf("%d",v[0]*v[v.size()-1]);
}
