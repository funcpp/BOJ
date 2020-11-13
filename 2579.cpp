#include <stdio.h>
int max(int a, int b);
int main()
{
	int n,maxn=0,jump=0;
	scanf("%d",&n);
	int num[301]={0};
	int plus[301]={0};
	for(int i=1; i<=n; i++)
	{
		scanf("%d",num+i);
		//plus[i]=num[i];
	}
	
	plus[1]=num[1];
	plus[2]=max(num[1] + num[2],num[2]);
	plus[3]=max(num[1]+num[3],num[2]+num[3]);
	
	for(int i=4; i<=n; i++)
	{
		plus[i]+=max(plus[i-3]+num[i-1]+num[i],plus[i-2]+num[i]);
	}
	printf("%d",plus[n]>=plus[3] ? plus[n] : plus[3]);
	return 0;
}

int max(int a, int b)
{
	return a>b ? a : b;
}
