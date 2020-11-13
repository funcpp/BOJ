#include <stdio.h>

int countf(int n);

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int pan[n][m]={0};
	
	int total=0,max=0;
	for(int i=0; i<n; i++)
	{
		int sum=0;
		for(int j=0; j<m; j++)
		{
			int num;
			scanf("%d",&num);
			pan[i][j]=countf(num);
			sum+=pan[i][j];
			total+=pan[i][j];
		}
		if(max<sum)
		{
			max=sum;
		}
	}
	
	int rmax=0;
	for (int i = 0; i < m; i++)
    {
        int rsum = 0;
        for (int j = 0; j < n; j++)
            rsum += pan[j][i];           
            
        if(rmax<rsum)
        {
        	rmax=rsum;
		}
    }
    
    int bbae = (rmax<max) ? max : rmax;
    printf("%d\n",total-bbae);
    return 0;
}

int countf(int n)
{
	int c=0;
	while(n>0)
	{
		if(n%10==9)
		{
			c++;
		}
		n/=10;
	}
	return c;
}
