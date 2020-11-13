#include <bits/stdc++.h>
using namespace std;

int n,m;
int _map[15][15];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int ans=0;
int pMap[15][15], ppMap[15][15];

void pr()
{
	printf("\n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			printf("%d ",ppMap[i][j]);
		}
		printf("\n");
	}
	return;
}

void count()
{
	int cnt=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(ppMap[i][j]==0)
			{
				cnt++;
			}
		}
	}
	if(cnt>ans) ans=cnt;
	return;
}

void virus(int x, int y)
{
	for(int i=0; i<4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(nx>=0 && nx<n && ny>=0 && ny<m)
		{
			if(ppMap[nx][ny]==0)
			{
				ppMap[nx][ny]=2;
				virus(nx,ny);
			}
		}
	}
	return;
}

void wall(int cnt)
{
	if(cnt==3)
	{
		memcpy(ppMap,pMap,sizeof(pMap));
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(ppMap[i][j]==2)
				{
					virus(i,j);
				}
			}
		}
		//pr();
		count();
		return;
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(pMap[i][j]==0)
			{
				pMap[i][j]=1;
				wall(cnt+1);
				pMap[i][j]=0;
			}
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%1d",&_map[i][j]);
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(_map[i][j]==0)
			{
				memcpy(pMap,_map,sizeof(_map));
				pMap[i][j]=1;
				wall(1);
				pMap[i][j]=0;
			}

		}
	}
	
	printf("%d",ans);
	
	return 0;
}
