#include <stdio.h>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	
	int swapa=0,swapb=0;
	int i=100;
	while(a>0)
	{
		swapa+=(a%10) * i;
		a/=10;
		
		i/=10;
	}
	i=100;
	while(b>0)
	{
		swapb+=(b%10) * i;
		b/=10;
		
		i/=10;
	}
	
	int answer = (swapa>swapb) ? swapa : swapb;
	printf("%d\n",answer);
	
	return 0;;
}
