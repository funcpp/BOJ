#include <stdio.h>
#include <algorithm>

int N;
int map[30][30];
int chk[30][30];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int cnt[625];

int max;

void print()
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			printf("%d",map[i][j]);
		}
		printf("\n");
	}
	return;
}

void f(int x, int y, int num)
{
	map[x][y]=num;
	
	for(int i=0; i<4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(!(nx>=0 && nx<N && ny>=0 && ny<N))
		{
			continue;
		}
		
		if(chk[nx][ny]==0 && map[nx][ny]==1)
		{
			chk[nx][ny]=1;
			f(nx,ny,num);
		}
	}
	return;
}

int main()
{
	scanf("%d",&N);
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			scanf("%1d",&map[i][j]);
		}
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(map[i][j]!=0 && chk[i][j]==0)
			{
				max++;
				chk[i][j]=1;
				f(i,j,max+1);
			}
		}
	}

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(map[i][j]>1)
			{
				cnt[map[i][j]-2]++;
			}
		}
	}
	
	std::sort(cnt,cnt+max);
	printf("%d\n",max);
	
	for(int i=0; i<=max; i++)
	{
		if(cnt[i]!=0)
		{
			printf("%d\n",cnt[i]);
		}
	}
	return 0;
}
