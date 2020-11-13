#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;
#define pii pair<int, int>
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v;
	vector<pii> pv;
	
	unordered_map<int, bool> chk;
	for(int i=0; i<n; i++)
	{
		int a, b;
		scanf("%d %d",&a,&b);
		if(!chk.count(a))
		{
			chk[a]=true;
			v.push_back(a);
		}
		if(!chk.count(b))
		{
			chk[b]=true;
			v.push_back(b);
		}
		pv.push_back(make_pair(a,b));
	}
	
	sort(v.begin(),v.end());
	
	unordered_map<int, int> posidx;
	for(int i=0; i<v.size(); i++)
	{
		posidx[v[i]]=i;
	}
	int arr[v.size()+2]={0,};
	for(int i=0; i<n; i++)
	{
		pv[i].first = posidx[pv[i].first];
		pv[i].second = posidx[pv[i].second];
		
		for(int j=pv[i].first; j<=pv[i].second; j++)
		{
			arr[j]=i+1;
		}
	}
	
	int ans=0;
	unordered_map<int, bool> chk2;
	for(int i=0; i<v.size(); i++)
	{
		//printf("%d ",arr[i]);
		if(!chk2.count(arr[i]) && arr[i])
		{
			ans++;
			chk2[arr[i]]=true;
		}
	}
	printf("%d",ans);
	
	
	return 0;
}
