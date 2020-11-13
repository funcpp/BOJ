#include <stdio.h>
#define MOD 1000000007
int main()
{
	int N;
	scanf("%d",&N);
	
	printf("%llu",(((N-1)%MOD)*((N-1)%MOD)*(N%MOD))%MOD);
	return 0;
}
