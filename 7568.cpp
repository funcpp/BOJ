#include <stdio.h>

struct Info
{
	int w,h;
};

int main()
{
	int n;
	scanf("%d",&n);
	Info info[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d %d",&info[i].h,&info[i].w);
	}
	
	int cnt[n]={0,};
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(info[i].w<info[j].w && info[i].h<info[j].h)
			{
				cnt[i]++;
			}
		}
	}
	
	for(int i=0; i<n; i++) printf("%d ",cnt[i]+1);
	
	return 0;
}
