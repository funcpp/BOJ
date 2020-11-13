#include <stdio.h>
int main()
{
	int N=0;
	double score[1000]={0,};
	scanf("%d",&N);
	
	for(int i=0; i<N; i++)
	{
		scanf("%d",&score[i]);
	}
	
	double M=0;
	for(int i=0; i<N; i++)
	{
		if(M<score[i])
		{
			M=score[i];	
		}	
	}
	double total=0;
	for(int i=0; i<N; i++)
	{
		total+=(double)((score[i]/M)*100.0);
	}
	printf("%.2lf",total/N);
	return 0;
}
