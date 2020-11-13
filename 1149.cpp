#include <stdio.h>
int min2(int a, int b);
int min3(int a, int b, int c);
int main()
{
	int N;
	scanf("%d",&N);
	
	int cost[1000][3];
	int answer[1000][3];
	
	for(int i=0; i<N; i++)
	{
		scanf("%d %d %d",&cost[i][0],&cost[i][1],&cost[i][2]);
	}
	answer[0][0]=cost[0][0];
	answer[0][1]=cost[0][1];
	answer[0][2]=cost[0][2];
	
	for(int i=1; i<N; i++)
	{
		for(int j=0; j<3; j++)
		{
			switch(j)
			{
				case 0:
					answer[i][0]=cost[i][j]+min2(answer[i-1][1],answer[i-1][2]);
					break;
				case 1:
					answer[i][1]=cost[i][j]+min2(answer[i-1][0],answer[i-1][2]);
					break;
				case 2:
					answer[i][2]=cost[i][j]+min2(answer[i-1][1],answer[i-1][0]);
					break;
			}
		}
	}
	printf("%d\n",min3(answer[N-1][0],answer[N-1][1],answer[N-1][2]));
	return 0;
}

int min2(int a, int b)
{
	return (a<b) ? a : b;
}

int min3(int a, int b, int c)
{
	if(a<=b && a <=c)
	{
		return a;
	}
	else if( b <=a && b <=c)
	{
		return b;
	}
	else if(c<=a && c<=b)
	{
		return c;
	}
}
