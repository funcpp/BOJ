#include <stdio.h>
bool sosu(int n);
int main()
{
	int N;
	scanf("%d",&N);
	int count=0;
	for(int i=0; i<N; i++)
	{
		int n;
		scanf("%d",&n);
		if(sosu(n))
		{
			count++;
		}
	}
	
	printf("%d\n",count);
	return 0;
}

bool sosu(int n)
{

if(n==1)
{
	return false;	
}

for(int i=2; i<n; i++)
{
	if(n%i==0)
	{
		return false;
	}
}
return true;
}
