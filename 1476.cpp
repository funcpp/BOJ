#include <stdio.h>
int main()
{
	int E,S,M;
	scanf("%d %d %d",&E,&S,&M);
	
	int ans=1;
	
	while(true)
	{
		if((ans-E)%15==0 && (ans-S)%28==0 && (ans-M)%19==0)
		{
			break;
		}
		ans++;
	}
	printf("%d",ans);
	return 0;
}
