#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int min = 1000001;
    int max = -1000001;
	for(int i=0; i<n; i++)
	{
		int t;
		scanf("%d",&t);
		
		if(t<min) min=t;
		
		if(max<t) max=t;
		
	}
	
	printf("%d %d",min,max);
	
	return 0;
}
