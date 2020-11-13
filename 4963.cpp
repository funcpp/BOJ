#include <stdio.h>
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,1,-1,1,-1,-1,1};
int w,h;
int map[55][55];

int c=2;
void dfs(int x, int y)
{
	map[x][y]=c;
	for(int i=0; i<8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=0 && nx<w && ny>=0 && ny<h && map[nx][ny]==1)
		{
			dfs(nx,ny);
		}
	}
}

int main()
{
	while(true)
	{
		scanf("%d %d",&h,&w);
		if(!w&&!h) break;
		
		for(int i=0; i<w; i++)
		{
			for(int j=0; j<h; j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		
		for(int i=0; i<w; i++)
		{
			for(int j=0; j<h; j++)
			{
				if(map[i][j]==1)
				{
					dfs(i,j);
					//p();
					c++;
				}
			}
		}
		
		printf("%d\n",c-2);
		c=2;
	}
	
	return 0;
}
