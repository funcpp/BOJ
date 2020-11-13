#include <stdio.h>
#include <memory.h>

int n,m;
int map[305][305];
int chk[305][305];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void pr()
{
	printf("\n");
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
}

void dfs(int x, int y)
{
	chk[x][y]=1;
	
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=0 && nx<n && ny>=0 && ny<m && !chk[nx][ny] && map[nx][ny]!=0)
		{
			dfs(nx,ny);
		}
	}
}

void melt()
{
	int map2[305][305];
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			map2[i][j]=map[i][j];
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(map2[i][j]==0) continue;
			
			int waterCnt=0;
			for(int k=0; k<4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				
				if(nx>=0 && nx<n && ny>=0 && ny<m && map2[nx][ny]==0) waterCnt++;
			}
			map[i][j] = map2[i][j] < waterCnt ? 0 : map2[i][j]-waterCnt;
		}
	}
	return;
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	
	int ans=0;
	while(true)
	{
		memset(chk,0,sizeof(chk));
		
		int cnt=0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(map[i][j]!=0 && !chk[i][j])
				{
					cnt++;
					dfs(i,j);
				}
			}
		}
		//pr();
		//printf("%d\n",cnt);
		if(cnt==0)
		{
			printf("0");
			return 0;
		} 
		else if(cnt>=2)
		{
			printf("%d",ans);
			return 0;
		}
		
		melt();
		
		ans++;
	}
	
	printf("%d",ans);
	return 0;
}
