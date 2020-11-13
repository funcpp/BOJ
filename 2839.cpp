#include <stdio.h>
int main()
{
	int N,t=0,f=0;
	scanf("%d",&N);
	while(N!=0)
	{
		if(N%5==0)
		{
			f++;
			N-=5;
		}
		else if(N%3==0)
		{
			t++;
			N-=3;
		}
		else if(N>5)
		{
			f++;
			N-=5;
		}
		else
		{
			f=0;
			t=-1;
			break;
		}
	}
	
	printf("%d\n",t+f);
	
	return 0;
}
