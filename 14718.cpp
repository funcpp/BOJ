#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define piii pair<int,pair<int,int>>


int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	vector<int> av,bv,cv;
	
	for(int i=0; i<n; i++)
	{
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		
		//v.push_back({a,{b,c}});
		av.push_back(a);
		bv.push_back(b);
		cv.push_back(c);
		//pv.push_back(a);
		//pv.push_back(b);
		//pv.push_back(c);
	}

	//sort(pv.begin(), pv.end());
	//pv.erase(unique(pv.begin(), pv.end()), pv.end());
	
	int ans[3] = {1000000,1000000,1000000};
	
	for(int str : av)
	{
		for(int dex : bv)
		{
			for(int itg : cv)
			{
				int cnt = 0;
				
				for(int i=0; i<n; i++)
				{
					if(str>=av[i] && dex>=bv[i] && itg >= cv[i])
					{
						cnt++;
					}
					
					if(k <= cnt && str+dex+itg <= ans[0]+ans[1]+ans[2])
					{
						ans[0]=str;
						ans[1]=dex;
						ans[2]=itg;
					}
				}
			}
		}
	}
	printf("%d",ans[0]+ans[1]+ans[2]);
	return 0;
}
