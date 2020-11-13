#include <stdio.h>
#include <algorithm>
#include <math.h>

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int su[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d",&su[i]);
	}

	//std::sort(su,su+n);
	
	double min=987654321;
	for(int i=0; i<n-k+1; i++)
	{
		for(int j=k; j<n-i+1; j++)
		{
			int sum=0;
			for(int x=i; x<i+j; x++)
			{
				sum+=su[x];
			}
			double m=sum/(double)j;
			double sum2=0;
			for(int x=i; x<i+j; x++)
			{
				sum2+=(su[x]-m) * (su[x]-m);
			}
			double c = sqrt(sum2/(double)j);
			if(c<min)
			{
				min=c;
			}
		}
	}
	
	printf("%.11lf",min);
	
	return 0;
} 
