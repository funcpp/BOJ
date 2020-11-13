#include <stdio.h>
#include <algorithm>
#include <math.h>

long long int n;
int score[1000000];

int main()
{
	scanf("%lld",&n);
	if(n==0)
	{
		printf("0");
		return 0;
	}
	
	for(long long int i=0; i<n; i++)
	{
		scanf("%d",&score[i]);
	}
	std::sort(score,score+n);
	
	long long int kill = (long long int)round(n*0.15f);
	
	double sum=0;
	for(long long int i=kill; i<n-kill; i++)
	{
		sum+=score[i];
	}	
	double avr = sum / (n-kill*2);
	
	printf("%lld",(long long int)round(avr));
	
}
