#include <stdio.h>
int main()
{
	int X;
	scanf("%d",&X);
	int cg=0,sum=0;
	while(sum<X)
	{
		cg++;
		sum+=cg;
	}
	int t=cg;
	int a=1;
	for(int i=sum-cg+1; i<X; i++)
	{
		cg--;
		a++;
	}
	if(t%2==0)
	{
		int tt=cg;
		cg=a;
		a=tt;
	}
	printf("%d/%d",cg,a);
	return 0;
}
