#include <stdio.h>
#define ull unsigned long long
int T,N,M;
int main()
{
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d %d",&N,&M);
		
		ull a = 1;
		for(int i=M-N+1; i<=M; i++)
		{
			a*=i;
			if(i<=N) a/=i;
		}
		
		for(int i=1; i<=M-N; i++)if(i<=N)a/=i;
		
		printf("%llu\n",a);
	}
}
