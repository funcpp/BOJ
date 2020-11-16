#include <stdio.h>
int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	
	int arr[K+1] = {0,};
	
	for(int i=1; i<=K; i++)
	{
		arr[i]=i;
		N-=i;
	}
	
	if(N<0)
	{
		printf("-1"); return 0;
	}
	
	N%=K;
	int i = K;
	while(N)
	{
		arr[i]++;
		N--;
		i--;
	}
	
	printf("%d\n",arr[K]-arr[1]);
	return 0;
}
