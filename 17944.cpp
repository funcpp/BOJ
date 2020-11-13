#include <stdio.h>
int main()
{
	long long n,t;
	scanf("%lld %lld",&n,&t);
	
	if(t <= n*2)
	{
		printf("%d",t);
	}
	else
	{
		long long ans=0;
		bool down=false;
		for(int i=0; i<t; i++)
		{
			if(ans<n*2 && !down)
			{
				ans++;
				if(ans==n*2)
				{
					down=true;
				}
			}
			else if(down)
			{
				ans--;
				if(ans==1)
				{
					down=false;
				}
			}
			//printf("%d\n",ans);
		}
		printf("%lld",ans);
	}
	return 0;
}
