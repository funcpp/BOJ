#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	
	vector<pair<int,int> > ln(n);
	
	for(int i=0; i<n; i++)
	{
		scanf("%d %d",&ln[i].first, &ln[i].second);
	}
	
	sort(ln.begin(),ln.end());
	
	int l=ln[0].first, r=ln[0].second;
	int ans=0;
	
	for(int i=1; i<n; i++)
	{
		if(r < ln[i].first)
		{
			ans += r-l;
			l=ln[i].first;
			r=ln[i].second;
		}
		else
		{
			r=max(r,ln[i].second);
		}
	}
	ans+=r-l;
	
	printf("%d",ans);
	
	return 0;
}
