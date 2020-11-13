#include <stdio.h>
int n,m;
int map[101][101];

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
void outair(int x, int y, bool bMelt)
{
	map[x][y]=bMelt ? 0 : 2;
	int cmp  = (bMelt ? 2 : 0);
	
	for(int i=0; i<4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(nx>=0 && nx<n && ny>=0 && ny<m)
		{
			if(map[nx][ny]==cmp)
			{
				outair(nx,ny,bMelt);
			}
		}
	}
	
	return;
}

void melt(int x, int y)
{
	int cnt= 0;
	for(int i=0; i<4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(nx>=0 && nx<n && ny>=0 && ny<m)
		{
			if(map[nx][ny]==2)
			{
				cnt++;
			}
		}
	}
	
	if(cnt>=1)
	{
		map[x][y]=0;
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
	
	int ans = 0;
	int pans=0;
	
	while(true)
	{	
		outair(0,0,false);
		
		bool b=false;
		int chcnt=0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(map[i][j]==1)
				{
					melt(i,j);
					chcnt++;
					b=true;
				}
			}
		}
		
		if(!b) break;
		pans=chcnt;
		
		outair(0,0,true);
		
		ans++;
		
		
	}
	
	printf("%d\n",ans);
	printf("%d",pans);
	return 0;
}
