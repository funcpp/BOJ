#include <stdio.h>
int main()
{
	int n,x;
	int A[10000];
	scanf("%d %d",&n,&x);
	
	for(int i=0; i<n; i++)
	{
		scanf("%d",&A[i]);
	}
	
	for(int i=0; i< n; i++)
	{
		if(A[i] < x)
		{
			printf("%d ",A[i]);
		}
	}
	return 0;
}
