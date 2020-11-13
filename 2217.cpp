#include <stdio.h>
#include <algorithm>

bool cmp(int a, int b)
{
	return a>b;
}
int main()
{
	int n;
	scanf("%d",&n);
	int rope[n]={0,};
	
	for(int i=0; i<n; i++)
	{
		scanf("%d",&rope[i]);
	}
	
	std::sort(rope,rope+n,cmp);
	
	int max=0;
	
	
	for(int i=0; i<n; i++)
	{	
		long long t = rope[i] * (i+1);
		if(t > max)
		{
			max=t;
		}
	}
	
	printf("%d",max);
	
	return 0;
}
