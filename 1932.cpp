#include <stdio.h>
int maxf(int a, int b);
int main()
{
	int n;
	scanf("%d",&n);
	
	int num[501][501]={0};
	int max=0;
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			scanf("%d",&num[i][j]);

			if(j==1)
			{
				num[i][j]+= num[i-1][j];
			}
			else if(j==i)
			{
				num[i][j]+= num[i-1][j-1];
			}
			else
			{
				num[i][j]+=maxf(num[i-1][j-1],num[i-1][j]);
			}
			
			
			if(max <= num[i][j])
			{
				max=num[i][j];
			}
			
		}
	}
	
	printf("%d\n",max);
	return 0;
}

int maxf(int a, int b)
{
	if(a>b)
	{
		return a;
	}
	else
		return b;
}
