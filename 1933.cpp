#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct bd
{
	int l,h,r;
	
	bool operator<(const struct bd &b)
	{
		if(b.l == l) return h > b.h;
		return b.l > l;
	}
};

int main()
{
	int N;
	scanf("%d",&N);
	vector<bd> v(N);
	
	for(int i=0; i<N; i++)
	{
		scanf("%d %d %d",&v[i].l, &v[i].h, &v[i].r);
	}
	
	sort(v.begin(),v.end());
	
	int left=v[0].l, right=v[0].r, height = v[0].h;
	printf("%d %d ",left, height);
	for(int i=1; i<N; i++)
	{
		if(v[i].l <= right)
		{
			if(v[i].r <= right)
			{
				if(height < v[i].h)
				{
					height = v[i].h;
					printf("%d %d ",v[i].l, height);
				}
			}
			else
			{
				right = v[i].r;
				
				if(height < v[i].h)
				{
					height = v[i].h;
					printf("%d %d ",v[i].l, height);
				}
			}
		}
		else
		{
			printf("%d %d ",right, 0);
			left = v[i].l;
			right = v[i].r;
			height = v[i].h;
			printf("%d %d ", left, height);
		}
	}
		
	return 0;
}
