#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
	double R;
	scanf("%lf",&R);
	
	double ans1=R*R*M_PI;
	double ans2=(2*R)*(2*R)/2;
	
	printf("%lf\n%lf",ans1,ans2);
	return 0;
}
