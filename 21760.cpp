#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		int n,m,k,d;
		scanf("%d %d %d %d",&n,&m,&k,&d);
		long long int C = n*m*((m-1)*k+m*(n-1))/2;
		long long int B = floor((double)d/C);
		printf("%lld\n",B?C*B:-1);
	}
	
	return 0;
}
