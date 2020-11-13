#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int dist2(pair<int,int> p, pair<int,int> p2)
{
	return (p.first-p2.first)*(p.first-p2.first) + (p.second-p2.second) *(p.second-p2.second);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		vector<pair<int, int> > v;
		
		for(int i=0; i<4; i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			v.push_back({x,y});
		}
		
		vector<int> len;
		
		for(int i=0; i<4; i++)
		{
			for(int j=i+1; j<4; j++)
			{
				len.push_back(dist2(v[i],v[j]));
			}
		}
		
		sort(len.begin(),len.end());
		int len1 = len[0], len2= 0;
		int len1C=1, len2C=0;
		for(int i=1; i<6; i++)
		{
			if(len[i]==len1)
			{
				len1C++;
			}
			else if(!len2 || len2==len[i])
			{
				len2=len[i];
				len2C++;
			}
		}
		
		printf("%d\n",(len1C==4 && len2C==2) ? 1 : 0);
	}
	return 0;
}
