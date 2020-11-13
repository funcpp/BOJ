#include <stdio.h>
#include <memory.h>

int T,M,N,K;
int map[55][55];
int cnt=1;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int x, int y)
{
	map[x][y]=cnt;
	for(int i=0; i<4; i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(nx>=0 && nx<M && ny>=0 && ny<N)
		{
			if(map[nx][ny]==1)
			{
				dfs(nx,ny);
			}
		}
	}
	return;
}


int main()
{
	scanf("%d",&T);
	while(T--)
	{
		cnt=1;
		memset(map,0,sizeof(map));
		scanf("%d %d %d",&M,&N,&K);
		for(int i=0; i<K; i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			map[x][y]=1;
		}
		
		for(int i=0; i<M; i++)
		{
			for(int j=0; j<N; j++)
			{
				if(map[i][j]==1)
				{
					cnt++;
					dfs(i,j);
				}
			}
		}
		
		printf("%d\n",cnt-1);
	}
	return 0;
}
