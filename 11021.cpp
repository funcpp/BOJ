#include <bits/stdc++.h>
int main()
{
	int n;
	scanf("%d",&n);
	
	int x=1;
	while(n--)
	{
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		printf("Case #%d: %d\n",x++,t1+t2);
	}
	return 0;
}
