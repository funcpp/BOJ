#include <stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		int n;
		scanf("%d",&n);
		
		int arr[2][n]={0,};
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<n; j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		
		
	}
	return 0;
}
