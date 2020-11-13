#include <stdio.h>
int min(int a, int b) {return a<b?a:b;}
int main()
{
	int N,M,K,ans=0;
	scanf("%d %d %d",&N,&M,&K);
	while(true)
	{
		if(N>=2 && M>=1 && N+M-3>=K)
		{
			N-=2;
			M-=1;
			ans++;
		} else break;
	}
	printf("%d",ans);
}
