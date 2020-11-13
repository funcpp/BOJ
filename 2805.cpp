#include <stdio.h>
#include <algorithm>
using namespace std;

long long n,m;
long long arr[1000005];
long long sum[1000005];
long long mh=0;
long long total=0;

long long get(int h)
{
    long long idx = upper_bound(arr,arr+n,h)-arr;
    long long m=0;
    if(idx) m = sum[idx-1];
    long long s = total-(n-idx)*h-m;
    //printf("%d %d\n",idx,s);
    return s;
}
int main()
{
    scanf("%lld %lld",&n,&m);
    
    for(int i=0; i<n; i++)
    {
        scanf("%lld",arr+i);
        mh=max(mh,arr[i]);
    }
    
    sort(arr,arr+n);
    
    
    for(int i=0; i<n; i++)
    {
        sum[i] = i?sum[i-1]+arr[i]:arr[i];
        total+=arr[i];
    }
    
    long long ans=0;
    
    if(total==m) ans=0;
    else
    {
        int left=0,right=mh;
        
        while(left<right)
        {
            int mid = (left+right)/2;
            long long g = get(mid);
            //printf("mid : %d g : %lld %d %d\n", mid, g, left, right);
            
            if(g>m)
            {
                ans=mid;
                left=mid + 1;
            }
            else
            {
                right=mid-1;
            }
        }
    }
    
	for(long long i = ans + 2; i >= ans - 2; i--)
	{
		long long g = get(i);
		if(g >= m)
		{
			printf("%lld", i);
			break;
		}
	}

    
    return 0;
}
