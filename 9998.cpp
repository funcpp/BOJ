#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

long long N;
long long b1[300005], b2[300005];

long long getAns(long long h)
{
	long long ret = 0;
	for(int i=0; i<N; i++)
	{
		long long height = h + abs(N/2 - i);
		ret+=abs(b1[i]-height) + abs(b2[i]-height);
	}
	
	return ret;
}

long long getAns2(long long h)
{
	long long mid = (N)/2;
	long long left = mid-1, right = mid+1;
	long long ret=abs(b1[mid]-h)+abs(b2[mid]-h);
	while(0<=left && right<N)
	{
		h++;
		ret +=abs(b1[left]-h)+abs(b1[right]-h)+abs(b2[left]-h)+abs(b2[right]-h);
		left--;
		right++;
	}
	
	return ret;
}

int main()
{
	scanf("%lld",&N);
	
	long long maxh=0;
	
	for(long long i=0; i<N; i++)
	{
		scanf("%lld",b1+i);
		maxh=maxh<b1[i]?b1[i]:maxh;
	}
	
	for(long long i=0; i<N; i++)
	{
		scanf("%lld",b2+i);
		maxh=maxh<b2[i]?b2[i]:maxh;
	}
	
	long long left = 0, right = 1e12 - (N-1)/2;
	long long minCnt=getAns2(left), maxCnt=getAns2(right);
	
	while(left<=right)
	{
		long long mid = (left+right)/2;
		
		if(minCnt < maxCnt) 
		{
			right = mid-1;
			maxCnt = getAns2(right);
		}
		else
		{
			left=mid+1;
			minCnt=getAns2(left);
		}
	}
	
	printf("%lld",min(minCnt,maxCnt));
	
	return 0;
}
