#include<bits/stdc++.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x1,y1,r1,x2,y2,r2;
		scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
		
		double dist = sqrtf(powf(x2-x1,2)+powf(y2-y1,2));
		double delta = fabs(r1-r2);
		
		if(x1==x2 && y1==y2)
			printf("%d\n",delta?0:-1);
		else if(dist < r1+r2 && delta<dist)
			printf("2\n");
		else if(dist == delta || dist == r1+r2)
			printf("1\n");
		else
			printf("0\n");
	}
	
	return 0;
}
