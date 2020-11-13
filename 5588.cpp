#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int m;
	scanf("%d",&m);
	
	vector<pair<int, int> > v;
	vector<pair<int, int> > dif;
	
	for(int i=0; i<m; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		v.push_back({x,y});
	}
	
	sort(v.begin(),v.end());
	
	for(int i=1; i<m; i++)
	{
		dif.push_back({v[0].first - v[i].first, v[0].second - v[i].second});
	}
	
	int difSize = dif.size();
	
	int n;
	scanf("%d",&n);
	
	vector<pair<int, int> > star;
	map<pair<int, int>, bool> isStar;
	
	for(int i=0; i<n; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		star.push_back({x,y});
		isStar[{x,y}]=true;
	}
	
	for(int i=0; i<n; i++)
	{
		bool found=true;
		for(int j=0; j<difSize; j++)
		{
			if(isStar.count({star[i].first - dif[j].first,star[i].second - dif[j].second}))
			{
				continue;
			}
			else
			{
				found=false;
				break;
			}
		}
		
		if(found)
		{
			printf("%d %d\n",star[i].first - v[0].first, -v[0].second + star[i].second);
			return 0;
		}
	}
	
	return 0;
}
