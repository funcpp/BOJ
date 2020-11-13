#include <stdio.h>
int main()
{
	int N,count=1;
	int l=1;
	
	scanf("%d",&N);
	
	for(int i=0; (l<N); i++)
	{
		l+=6*count;
		count++;
	}
	
	printf("%d\n",count);
	return 0;
}
