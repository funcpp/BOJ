#include <stdio.h>
int main()
{
	int N,K;
	scanf("%d %d",&N, &K);
	
	int base = (K)*(K+1)/2;
	if(N<base) printf("-1");
	else
	{
		int arr[K+5]={0,};
		for(int i=1;i<=K;i++){
			arr[i]=i;
			N-=i;
		}
		N%=K;
		for(int i=K;i>=1;i--){
			if(N)
			{
				arr[i]++;
				N--;
			}
		}
		printf("%d",arr[K]-arr[1]);
	}
	return 0;
}
