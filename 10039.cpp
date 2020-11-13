#include <stdio.h>
int main()
{
	int scr[5]={0};
	int sum=0;
	for(int i=0; i<5; i++)
	{
		scanf("%d",scr+i);
		if(*(scr+i)<40)
			*(scr+i)=40;
			
		sum+=*(scr+i);
	}
	printf("%d\n",sum/5);
	return 0;
}
