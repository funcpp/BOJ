#include <stdio.h>
int n;
int map[105][105];
int pmap[105][105];

int maxh, minh=987654;
int cnt=1;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void pr()
{
	printf("\n");
	for(int i=0; i<n; i++)
	{
		for(int j=0;j <n;j ++)
		{
			printf("%8d ",pmap[i][j]);
		}
		printf("\n");
	}
	return;
}

void dfs(int x, int y)
{
	pmap[x][y]=cnt;
	
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=0 && nx<n && ny>=0 && ny<n)
		{
			if(pmap[nx][ny]==0)	dfs(nx,ny);
		}
	}
}

int count()
{
	cnt=1;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(pmap[i][j]==0)
			{
				dfs(i,j);
				cnt++;
			}
		}
	}
	return cnt-1;
}

int main()
{
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d",&map[i][j]);
			maxh = maxh < map[i][j] ? map[i][j] : maxh;
			minh = map[i][j] < minh ? map[i][j] : minh;
		}
	}
	
	int ans = 1;
	
	for(int i=minh; i<maxh; i++)
	{
		for(int a=0; a<n; a++)
		{
			for(int b=0; b<n; b++)
			{
				pmap[a][b] = map[a][b] <= i ? 987654 : 0; //Àá°äÀ¸¸é Á¿°°Àº¼ýÀÚ 
			}
		}
		
		int c= count();
		//pr();
		
		//if(c!=n*n)
		ans = ans < c ? c : ans;
		
	}
	
	
	printf("%d",ans);
	
	return 0;
}
