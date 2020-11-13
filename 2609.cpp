#include <stdio.h>
#define max(a,b) a<b?b:a
#define min(a,b) a<b?a:b

int f(int n, int m)
{
	if(n%m==0) return m;
	else return f(m,n%m);
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	
	int d=f(n,m);
	printf("%d\n%d",d,n*m/d);
	
	return 0;
}
