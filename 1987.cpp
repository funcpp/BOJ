#include <stdio.h>
int R,C;
int map[25][25];
int chk[1000];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int ans=0;

void dfs(int x, int y, int cnt)
{
	if(cnt > ans) ans = cnt;
	
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=0 && nx<R && ny>=0 && ny<C && !chk[map[nx][ny]])
		{
			chk[map[nx][ny]]=1;
			dfs(nx,ny,cnt+1);
			chk[map[nx][ny]]=0;
		}
	}
	return;
}

int main()
{
	scanf("%d %d",&R,&C);
	for(int i=0; i<R; i++)
	{
		char s[C+5];
		scanf("%s",s);
		for(int j=0; j<C; j++)
		{
			map[i][j] = s[j];
		}
	}
	
	chk[map[0][0]]=1;
	dfs(0,0,1);
	
	printf("%d",ans);
	
	return 0;
}
