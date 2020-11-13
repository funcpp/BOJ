#include <stdio.h>

int map[12][6];
int tempNum=101;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int cnt=0;
void bomb(bool isBomb)
{
	for(int i=0; i<12; i++)
	{
		for(int j=0; j<6; j++)
		{
			if(map[i][j]==tempNum)
			{
				map[i][j] = isBomb ? 0 : map[i][j]-100;
			}
		}
	}
}

void dfs(int x, int y)
{
	cnt++;
	map[x][y]=tempNum;
	for(int i=0; i<4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(nx>=0 && nx<12 && ny>=0 && ny<6 && map[x][y] - map[nx][ny] == 100)
		{
			dfs(nx,ny);
		}
	}
}

int bombCnt()
{
	int ret=0;
	for(int i=0; i<12; i++)
	{
		for(int j=0; j<6; j++)
		{
			if(map[i][j]>0 && map[i][j] <= 5)
			{
				cnt=0;
				tempNum=map[i][j]+100;
				dfs(i,j);
				if(cnt>=4)
				{
					bomb(true);
					ret++;
				}
				else bomb(false);
			}
		}
	}
	return ret;
}

void down()
{
	bool down;
	while(true)
	{
		down=false;
		for(int i=10; i>=0; i--) //밑에서부터 
		{
			for(int j=0; j<6; j++)
			{
				if(map[i][j]!=0 && map[i+1][j]==0)
				{
					int t =map[i][j];
					map[i][j]=0;
					map[i+1][j]=t;
					down=true;
				}
			}
		}
		
		if(!down) break;
	}
	return;
}

void pr()
{
	printf("\n");
	for(int i=0; i<12; i++)
	{
		for(int j=0; j<6; j++)
		{
			printf("%d",map[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	for(int i=0; i<12; i++)
	{
		char s[10];
		scanf("%s",s);
		for(int j=0; j<6; j++)
		{
			if(s[j]=='.') map[i][j] = 0;
			else if(s[j]=='Y') map[i][j] = 1;
			else if(s[j]=='G') map[i][j] = 2;
			else if(s[j]=='R') map[i][j] = 3;
			else if(s[j]=='P') map[i][j] = 4;
			else if(s[j]=='B') map[i][j] = 5;
		}
	}
	
	int ans=0;
	while(true)
	{
		//pr();
		
		if(bombCnt()==0) break;
		
		down();
	
		ans++;
	}
	
	printf("%d",ans);
	return 0;
}
