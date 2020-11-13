#include <stdio.h>
int main()
{	
	int n,answer=0;
	scanf("%d",&n);
	
	for(int i=1; i<=n; i++)
	{
		answer+=i;
	}
	
	printf("%d\n",answer);
	return 0;
}
