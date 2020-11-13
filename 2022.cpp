#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

double a,b,c;
double a2,b2;

double getC(double d)
{
	double d2 = d*d;
	double p1 = sqrtf(a2-d2);
	double p2 = sqrtf(b2-d2);
	
	double _ = (p1*p2) / (p1+p2);
	return _;
}

int main()
{	
	scanf("%lf %lf %lf",&a,&b,&c);
	a2 = a*a, b2 = b*b;
	
	double left = 0, right = min(a,b);
	double mid;
	
	while(left < right)
	{
		mid = (left+right)/2.f;
		
		double cc = getC(mid);
		
		if(cc < c)
		{
			right = mid;
		} 
		else
		{
			left = mid;
		}
		
		if(right - left < 1e-3) break;
	}
	
	printf("%lf",mid);
	
	return 0;
}
