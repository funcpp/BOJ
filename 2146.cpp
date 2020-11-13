#include <stdio.h>
#include <memory.h>
#include <vector>
#include <math.h>

int ans = 987654321;

int n;
int originMap[105][105];
int map[105][105];
int chk[105][105];
int cnt=2;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct ddang
{
	int x,y,num;
	ddang(int x, int y, int num):x(x),y(y),num(num){};
};

std::vector<ddang> dv;

/*int originLandCnt;

void dfs(int x, int y)
{
	chk[x][y]=1;
	
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=0 && nx<n && ny>=0 && ny<n && !chk[nx][ny] && map[nx][ny]==1)
		{
			dfs(nx,ny);
		}
	}
}

int landCnt()
{
	memset(chk,0,sizeof(chk));
	
	int ret=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(!chk[i][j] && map[i][j]==1)
			{
				ret++;
				dfs(i,j);
			}
		}
	}
	return ret;
}

void dfs2(int x, int y, int cnt)
{
	if(ans < cnt) return;
	if(landCnt()<originLandCnt)
	{
		if(cnt < ans)
		{
			ans = cnt;
		}
		return;
	}
	
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=0 && nx<n && ny>=0 && ny<n && map[nx][ny]==0)
		{
			map[nx][ny]=1;
			dfs2(nx,ny,cnt+1);
			map[nx][ny]=0;
		}
	}
}*/

void dfs(int x, int y)
{
	chk[x][y]=1;
	map[x][y]=cnt;
	
	dv.push_back(ddang(x,y,cnt));
	
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=0 && nx<n && ny>=0 && ny<n && map[nx][ny]==1 && !chk[nx][ny])
		{
			dfs(nx,ny);
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d",&originMap[i][j]);
			map[i][j]=originMap[i][j];
		}
	}
	
	//originLandCnt = landCnt();
	
	/*for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(map[i][j]==0)
			{
				map[i][j]=1;
				dfs2(i,j,1);
				map[i][j]=0;
			}
		}
	}*/
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(map[i][j]==1)
			{
				dfs(i,j);
				cnt++;
			}
		}
	}
	
	/*for(int i=0; i<dv.size(); i++)
	{
		for(int j=0; j<dv.size(); j++)
		{
			printf("%d %d\n",dv[i].num,dv[j].num);
		}
	}*/
	
	for(int i=0; i<dv.size(); i++)
	{
		for(int j=0; j<dv.size(); j++)
		{
			if(i==j) continue;
			if(dv[i].num == dv[j].num) continue;
			
			//printf("%d %d\n",dv[i].num,dv[j].num);
			int d = abs(dv[j].x - dv[i].x) + abs(dv[j].y - dv[i].y) - 1;
			
			if(d<ans)
			{
				ans=d;
			}
		}
	}
	
	printf("%d",ans);
	
	return 0;
}
