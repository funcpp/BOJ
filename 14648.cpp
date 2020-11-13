#include <stdio.h>
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	int num[1000],qu[4];
	
	for(int i=0; i<n; i++)
	{
		scanf("%d",num+i);
	}
	for(int i=0; i<q; i++)
	{
		int m;
		scanf("%d",&m);
		
		if(m==1)
		{
			long long sum=0;
			for(int k=0; k<2; k++)
				scanf("%d",&qu[k]);
				
			for(int k=qu[0]-1; k<qu[1]; k++)
			{
				sum+=num[k];
			}
			int t=num[qu[0]-1];
			num[qu[0]-1]=num[qu[1]-1];
			num[qu[1]-1]=t;
			printf("%lld\n",sum);
		}
		else if(m==2)
		{
			for(int k=0; k<4; k++)
				scanf("%d",&qu[k]);
				
			long long sum=0;
			for(int k=qu[0]-1; k<qu[1]; k++)
			{
				sum+=num[k];
			}
			for(int k=qu[2]-1; k<qu[3]; k++)
			{
				sum-=num[k];
			}
			printf("%lld\n",sum);
		}
	}
	
	return 0;
}
