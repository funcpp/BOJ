#include <stdio.h>
#include <algorithm>

int M,N;
int map[505][505];
int dp[505][505];

int dx[2] = {1,0};
int dy[2] = {0,1};

void dfs(int x, int y)
{
	for(int i=0; i<2; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=0 && nx<M && ny>=0 && ny<N)
		{
			if(map[x][y] > map[nx][ny])
			{
				dp[nx][ny]++;
				dfs(nx,ny);
			}
		}
	}
}

int main()
{
	scanf("%d %d",&M,&N);
]

	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	
	dfs(0,0);
	
	printf("%d",dp[M-1][N-1]);
	return 0;
}
