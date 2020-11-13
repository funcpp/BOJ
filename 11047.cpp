#include <stdio.h>
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int coin[n+1];
	int q=n;
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&coin[i]);
	}
	
	int sum=0,cnt=0;
	for(int j=q; j>0;j--)
	{
		cnt+=k/coin[j];
		k%=coin[j];
	}

	
	printf("%d",cnt);
}
