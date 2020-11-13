#include <stdio.h>
int N;
int score[20];
int R[20][20];
int PNum=0;

int main()
{
	scanf("%d",&N);
	
	for(int i=0; i<N; i++)
	{
		scanf("%d",score+i);
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			scanf("%d",&R[i][j]);
		}
	}
	
	scanf("%d",&PNum);
	
	
	
	return 0;
}
