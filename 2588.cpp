#include <bits/stdc++.h>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	
	printf("%d\n%d\n%d\n%d",n*(m%10),n*(m/10%10),n*(m/100%10),n*m);
	return 0;
}
