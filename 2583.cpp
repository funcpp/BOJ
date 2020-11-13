#include <stdio.h>
#include <algorithm>

int m,n;

int map[105][105];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int cnt=1;

void dfs(int x, int y)
{
	map[x][y]=cnt;
	
	for(int i=0; i<4; i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(nx>=0 && nx<m && ny>=0 && ny<n)
		{
			if(map[nx][ny]==0)
			{
				dfs(nx,ny);
			}
		}
	}
	return;
}

int count(int x)
{
	int ret=0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(map[i][j]==x)
			{
				ret++;
			}
		}
	}
	return ret;
}
int main()
{
	int k;
	scanf("%d %d %d",&m,&n,&k);
	
	while(k--)
	{
		int x1,x2,y1,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		
		for(int i=x1; i<x2; i++)
		{
			for(int j=y1; j<y2; j++)
			{
				map[j][i]=-1;
			}
		}
	}
	
	int ans[105];
	
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(map[i][j]==0)
			{
				dfs(i,j);
				ans[cnt-1] = count(cnt);
				cnt++;
				//printf("%d %d %d\n",i,j,cnt);
			}
		}
	}
	
	/*for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%2d ",map[i][j]);
		}
		printf("\n");
	}*/
	
	std::sort(ans,ans+cnt-1);
	
	printf("%d\n",cnt-1);
	for(int i=0; i<cnt-1; i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
