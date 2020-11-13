#include <stdio.h>
#include <math.h>
#define min(a,b) a<b?a:b
#define fuck 987654321

struct Point
{
	int x, y;
};

int floyd[105][105];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		Point pt[n+2];
		for(int i=0; i<n+2; i++)
		{
			scanf("%d %d",&pt[i].x,&pt[i].y);
		}
		
		for(int i=0; i<n+2; i++)
		{
			for(int j=0; j<n+2; j++)
			{
				if(i==j) continue;
				
				int d = abs(pt[i].x-pt[j].x) + abs(pt[i].y - pt[j].y);
				if(d<=1000)
				{
					floyd[i][j]=1;
				}
				else floyd[i][j]=fuck;
			}
		}
		
		for(int j=0; j<n+2; j++)
		{
			for(int i=0; i<n+2; i++)
			{
				for(int k=0; k<n+2; k++)
				{
					floyd[i][k] = min(floyd[i][k],floyd[i][j] + floyd[j][k]);
				}
			}
		}
		
		printf("%s\n",(0<floyd[0][n+1] && floyd[0][n+1] < 105) ? "happy" : "sad");
	}
}
