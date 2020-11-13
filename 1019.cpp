#include <stdio.h>
long long N;
long long cnt[10];
int div=1;

void f(long long i)
{
	while(i>0)
	{
		cnt[i%10]+=div;
		i/=10;
	}
	return;
}

int main()
{
	scanf("%d",&N);
	
	int start=1;
	while(start<=N)
	{
		while(N%10!=9 && start<=N)
		{
			f(N);
			N--;
		}
		
		if(N < start) break;
	
		while(start%10!=0 && start <= N)
		{
			f(start);
			start++;
		}
		
		start/=10;
		N/=10;
		
		for(int i=0; i<10; i++)
		{
			cnt[i]+=(N-start+1)*div;
		}
		
		div*=10;
	}
	
	for(int i=0; i<10; i++)
	{
		printf("%d ",cnt[i]);
	}
	return 0;
}
