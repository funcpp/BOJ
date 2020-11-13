#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int M,N;
int map[1005][1005];
int dx[4] ={1,-1,0,0};
int dy[4] ={0,0,1,-1};

struct PT
{
	int x,y;
};

bool isFinish()
{
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(map[i][j]==0)
				return false;	
		}
	}
	return true;
}

int main()
{
	scanf("%d %d",&N,&M);
	queue<PT> q;
	
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			scanf("%d",&map[i][j]);
			if(map[i][j]==1) q.push({i,j});
		}
	}
	
	while(!q.empty())
	{
		PT p = q.front();
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			
			if(nx>=0 && nx<M && ny>=0 && ny<N && map[nx][ny]==0)
			{
				map[nx][ny]=map[p.x][p.y]+1;
				q.push({nx,ny});
			}
		}
		
		/*
		for(int i=0; i<M; i++)
		{
			for(int j=0; j<N; j++)
			{
				printf("%d ",map[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
	}
	
	int max=0;
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(max<map[i][j]) max=map[i][j];
		}
	}
	
	printf("%d",isFinish() ? max-1 : -1);
	
	return 0;
}
