#include <stdio.h>
#include <math.h>

int main()
{
	int M,N;
	double sqrtM,sqrtN;
	int min,max;
	int j=0;
	int sum=0;
	scanf("%d %d",&M,&N);
	sqrtM=sqrt(M);
	sqrtN=sqrt(N);
	min=(int)sqrtM;
	max=(int)sqrtN;
	if(min<sqrtM)
		min++;
	if(sqrtN-sqrtM < 1)
	{
		printf("-1");
	}
	else
	{
		int num[max-min+1];
		for(int i=min; i<=max; i++)
		{
			num[j] = i*i;
			sum+=num[j];
			j++;
		}
	
		printf("%d\n%d",sum,num[0]);
	}
	return 0;
}
