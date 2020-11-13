#include <stdio.h>

struct _hw
{
	int pt, start, time, prev, cur;
};

int main()
{
	int n;
	scanf("%d",&n);
	_hw hw[n]={0,};
	
	for(int i=0; i<n; i++)
	{
		int k;
		scanf("%d",&k);
		if(k==1)
		{
			int _pt, _t;
			scanf("%d %d",&_pt,&_t);
			hw[i].pt=_pt;
			hw[i].time=_t;
			hw[i].prev=-1;
			hw[i].start=-1;
			hw[i].cur=0;
		}
	}
	
	int m=0;
	int pIdx=-1;
	int ans=0;
	
	while(true)
	{
		if(hw[m].pt != 0)
		{
			if(pIdx==-1)
			{
				hw[m].start=m;
				hw[m].cur++;
				pIdx=m;
			}
			else
			{
				hw[m].start=m;
				hw[m].cur++;
				hw[m].prev=pIdx;
				
				pIdx=m;
				
				if(hw[pIdx].cur==hw[pIdx].time)
				{
					ans+=hw[pIdx].pt;
					if(hw[pIdx].prev!=-1)
					{
						pIdx=hw[pIdx].prev;
					}
				}
			}
		}
		else
		{
			hw[pIdx].cur++;
			if(hw[pIdx].cur==hw[pIdx].time)
			{
				ans+=hw[pIdx].pt;
				if(hw[pIdx].prev!=-1)
				{
					pIdx=hw[pIdx].prev;
				}
			}
		}
		m++;
		if(m==n) break;
	}
	
	printf("%d",ans);
	
	return 0;
}
