#include <stdio.h>
int main()
{
	int P,N;
	scanf("%d\n%d",&P,&N);
	int location[100], RL[100];
	int dol[101]={0};
	for(int i=0; i<N; i++)
	{
		char c;
		scanf("%d %c",location+i,&c);
			
		if(c=='R')
		{
			for(int j=*(location+i)+1; j<101; j++)
			{
				dol[j]++;
			}
		}
		else if(c=='L')
		{
			for(int j=1; j<*(location+i); j++)
			{
				dol[j]++;
			}
		}
	}
	int a=0,b=0,c=0;
	for(int i=1; i<101; i++)
	{
		switch(dol[i]%3)
		{
			case 0: a++; break;
			case 1: b++; break;
			case 2: c++; break;
		}
	}
	printf("%.2lf\n%.2lf\n%.2lf",P/100.0*a,P/100.0*b,P/100.0*c);

	return 0;
}
