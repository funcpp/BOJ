#include <stdio.h>
#include <math.h>
int n;
int numSet[3] = {0,1,2};
int ans;

void solve(long long int num)
{
	if((int)log10(num)+1==n)
	{
		if(num%3==0) ans++;
		return;
	}
	
	for(int i=0; i<3; i++)
	{
		solve(num*10+numSet[i]);
	}
	return;
}

int main()
{
	scanf("%d",&n);
	solve(1);
	solve(2);
	printf("%d",ans);
	return 0;
}
