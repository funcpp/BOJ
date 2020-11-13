#include <stdio.h>
#include <math.h>

int main ()
{
	int n,count=0;
	scanf("%d",&n);
	
	for(int i=1; i<=n; i++)
	{
		if(i!=100100)
		{
			if(i < 100)
			{
				//printf("%d\n",i);
				count++;
			}
			else
			{
				int t=i;
				int z=t%10;
				int y=(t/10)%10;
				int x=t/100;
				
				if(abs(y-x)==abs(y-z))
				{
					count++;
					if(x==z && (x!=y || z!=y)) count--;
					//else printf("%d\n",i);
				}
			}
		}
	}
	
	printf("%d\n",count);
	return 0;
}
