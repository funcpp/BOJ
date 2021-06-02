#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	while(1)
	{
		scanf("%d",&a);
		
		if(!a) break;
		
		int b=0, t= a, k=1, c[10]={0,},i=0,j=0;
		while(t)
		{
			c[i++]=t%10;
			t/=10;
			k*=10;
		}
		while(j<=i)
		{
			k/=10;
			b+=c[j++]*k;
		}
		printf("%s\n",a==b?"yes":"no");
	}
	return 0;
}
