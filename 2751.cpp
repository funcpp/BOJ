#include <stdio.h>
#include <algorithm>
int main()
{
	int n;
	scanf("%d",&n);
	int num[n];
	
	for(int i=0; i<n; i++)
		scanf("%d",num+i);
		
	std::sort(num,num+n);
	
	for(int i=0; i<n; i++)
		printf("%d\n",num[i]);	
	return 0;
}
