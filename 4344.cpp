#include <stdio.h>
int main()
{
	int T,stu,count;
	double avg=0,sum=0,per=0;
	int score[1000]={0,};
	scanf("%d",&T);
	
	for(int i=0; i<T; i++)
	{
		score[1000]={0,};
		avg=0;
		sum=0;
		count=0;
		scanf("%d",&stu);
		for(int j=0; j<stu; j++)
		{
			scanf("%d",&score[j]);
			sum+=score[j];
		}
		avg=(double)sum/stu;
		for(int j=0; j<stu; j++)
		{
			if(score[j]>avg)
			{
				count++;
			}
		}
		per=(double)count/stu;
		printf("%.3lf%%\n",per*100.000);
	}
	return 0;
}
