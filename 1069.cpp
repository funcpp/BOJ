#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int X,Y,D,T;
double ans=987654321;

int main()
{
	scanf("%d %d %d %d",&X,&Y,&D,&T);
	double dist = sqrtf(X*X+Y*Y);
	
	ans = min(dist,fabs(D-dist));
	for(int i=2; i<2000; i++)
		ans = min(ans, D*i < dist ? i*T+dist-i*D: i*T);
	
	printf("%.11lf",ans);
	
	return 0;
}
