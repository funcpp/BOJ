#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	long long int arr[92]={0,1,1,2,0,};
	for(int i=4; i<=n; i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
	}
	printf("%lld",arr[n]);
	return 0;
}
