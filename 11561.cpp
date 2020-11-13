#include <stdio.h>
#include <algorithm>

#define uint64_t unsigned long long

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		uint64_t n;
		scanf("%lld",&n);
		
		uint64_t ans=0;
		uint64_t left=1, right=n;
		
		while(left <= right)
		{
			uint64_t mid = (left + right)/2;
			
			if(mid*(mid+1) <= n*2)
			{
				left = mid+1;
				ans=max(ans,mid);

			}
			else
				right = mid-1;
		}
		
		printf("%llu\n",ans);
	}
	
	return 0;
}
