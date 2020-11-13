#include <stdio.h>

struct line
{
	int giulgi;
	int x1=0,x2=0,y1=0,y2=0;
};


int main()
{	
	int T;
	scanf("%d",&T);
	struct line l[T];
	int count=0;
	
	for(int i=0; i<T; i++)
	{
		int x1,x2,y1,y2;
		scanf("%d %d %d %d",&x1,&x2,&y1,&y2);
		int gix = x2-x1;
		int giy = y2-y1;
		if(gix==0) gix=1;
		if(giy==0) giy=1;
		
		l[i].giulgi = giy/gix;
		if(x1<x2)
		{
			l[i].x1 = x1;
			l[i].x2 = x2;
		}
		else
		{
			l[i].x1 = x2;
			l[i].x2 = x1;
		}
		
		if(y1<y2)
		{
			l[i].y1 = y1;
			l[i].y2 = y2;
		}
		else
		{
			l[i].y1 = y2;
			l[i].y2 = y1;
		}
		
		for(int j=0; j<i; j++)
		{
			if(((l[i].x1 >= l[j].x1 && l[i].x2 <= l[j].x2) || (l[i].x1 <= l[j].x1 && l[i].x2 >= l[j].x2)) && ((l[i].y1 >= l[j].y1 && l[i].y2 <= l[j].y2) || (l[i].y1 <= l[j].y1 && l[i].y2 >= l[j].y2)) && l[i].giulgi != l[j].giulgi)
			{
				count++;
			}
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}
