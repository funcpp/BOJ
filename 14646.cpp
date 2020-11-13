#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	bool c[n+1]={false};
	int count=0,max=0;
	for(int i=0; i<n*2; i++)
	{
		int m;
		scanf("%d",&m);
		c[m] ? count-- : count++;
		c[m] = !c[m];
		if(count>max)
		{
			max=count;
		}
	}
	
	printf("%d\n",max);
	return 0;
} 
