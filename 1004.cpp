#include <stdio.h>
#include <math.h>
int main(){
	int T,T2,x1,x2,y1,y2,answer=0;
	scanf("%d",&T);
	for(int i=0; i<T; i++)
	{
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		scanf("%d",&T2);
		for(int j=0; j<T2; j++)
		{
			int Cx,Cy,R;
			double distance, distance2;
			scanf("%d %d %d",&Cx,&Cy,&R);
			
			distance=sqrt(pow(Cx-x1,2) + pow(Cy-y1,2));
			distance2=sqrt(pow(Cx-x2,2) + pow(Cy-y2,2));
			
			if((distance < R && distance2>R) || (distance>R && distance2<R))
				answer++;
		}
		printf("%d\n",answer);
		answer=0;
	}
	return 0;
}
