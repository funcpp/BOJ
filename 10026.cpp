#include <stdio.h>
#include <memory.h>

int n;
int map[105][105];
int chk[105][105];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int cnt=1;

void dfs(int x, int y)
{	
	chk[x][y]=1;
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=0 && nx<n && ny>=0 && ny<n && !chk[nx][ny])
		{
			if(map[nx][ny]==map[x][y])
			{
				dfs(nx,ny);
			}
		}
	}
	
	return;
}

void dfs2(int x, int y)
{	
	chk[x][y]=1;
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=0 && nx<n && ny>=0 && ny<n && !chk[nx][ny])
		{
			if((map[nx][ny]==map[x][y]) || (map[nx][ny]==0 && 1==map[x][y]) || (map[nx][ny]==1 && 0==map[x][y]))
			{
				dfs2(nx,ny);
			}
		}
	}
	
	return;
}

int main()
{
	scanf("%d",&n);
	
	for(int i=0; i<n; i++)
	{
		char s[n+2];
		scanf("%s",s);
		for(int j=0; j<n; j++)
		{
			if(s[j]=='R') map[i][j]=0;
			else if(s[j]=='G') map[i][j]=1;
			else if(s[j]=='B') map[i][j]=2;
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(!chk[i][j])
			{
				dfs(i,j);
				cnt++;
			}
		}
	}
	
	printf("%d ",cnt-1);
	memset(chk,0,sizeof(chk));
	cnt=1;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(!chk[i][j])
			{
				dfs2(i,j);
				cnt++;
			}
		}
	}
	
	printf("%d ",cnt-1);
	
	return 0;
}
