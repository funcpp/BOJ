#include <stdio.h>
int main()
{
	int stick=64;
	int x;
	scanf("%d",&x);
	int ans=0;
	while(x>0)
	{
		if(x%2==1)
		{
			ans++;
		}
		x/=2;
	}
	printf("%d\n",ans);
	return 0;
}
