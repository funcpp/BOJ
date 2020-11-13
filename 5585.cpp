#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int ans=0;
	n=1000-n;
	while(n!=0)
	{
		if(n>=500)
		{
			n-=500;
			ans++;
		}
		else if(n>=100)
		{
			n-=100;
			ans++;
		}
		else if(n>=50)
		{
			n-=50;
			ans++;
		}
		else if(n>=10)
		{
			n-=10;
			ans++;
		}
		else if(n>=5)
		{
			n-=5;
			ans++;
		}
		else if(n>=1)
		{
			n-=1;
			ans++;
		}
	}
	
	printf("%d",ans);
	return 0;
}
