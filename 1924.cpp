#include <stdio.h>
int main()
{	
	int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	char yoil[7][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
	int x,y,total=0;
	scanf("%d %d",&x,&y);
	
	for(int i=0; i<x-1; i++)
	{
		total+=days[i];
	}
	total+=y;
	
	printf("%s\n",yoil[total%7]);
	return 0;
}
