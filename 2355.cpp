#include <stdio.h>
#include <math.h>
int main()
{
	long long int A,B;
	
	scanf("%lld %lld",&A,&B);
	long long int ans=0;
	
	ans = (A<=B) ? ((B-A+1) * (A+B) /2 ) : ((A-B+1) * (A+B) /2 );
	
	printf("%lld",ans);
	
	return 0;
}
