#include <stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		int N,M;
		scanf("%d %d",&N,&M);
		
		unsigned long long a = 1;
		for(int i=M-N+1; i<=M; i++)
		{
			a*=i;
			if(i<=N) a/=i;
		}
		
		for(int i=1; i<=M-N; i++)
		{
			if(i<=N)
				a/=i;
		}
		
		printf("%llu\n",a);
	}
}
