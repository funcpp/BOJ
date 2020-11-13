#include <stdio.h>
#include <algorithm>

int N,M;
int arr[505][505];
int chk[505][505];
int ans=0;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(int x, int y, int cnt)
{
	if(cnt==4)
	{
		return arr[x][y];
	}
	
	
	int ret=0;
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(0<=nx && nx<N && 0<=ny && ny<M && !chk[nx][ny])
		{
			chk[nx][ny]=1;
			ret=std::max(ret,arr[x][y] + bfs(nx,ny,cnt+1));
			chk[nx][ny]=0;
		}
	}
	
	return ret;
}

int fuck(int x, int y)
{
	int ret=0;
	
	//ぬ, で 
	if(x+2<N && y+1 < M)
	{
		ret = std::max(ret,arr[x][y]+arr[x+1][y]+arr[x+1][y+1]+arr[x+2][y]);
		ret = std::max(ret,arr[x][y+1]+arr[x+1][y+1]+arr[x+1][y]+arr[x+2][y+1]);
	}
	
	//た,っ 
	if(x+1<N && y+2 < M)
	{
		ret = std::max(ret,arr[x][y]+arr[x][y+1]+arr[x+1][y+1]+arr[x][y+2]);
		ret = std::max(ret,arr[x+1][y]+arr[x+1][y+1]+arr[x][y+1]+arr[x+1][y+2]);
	}
	
	return ret;
}

int main()
{
	scanf("%d %d",&N,&M);
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			scanf("%d",&arr[i][j]);
		}	
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			chk[i][j]=1;
			ans = std::max(ans,bfs(i,j,1));
			ans = std::max(ans,fuck(i,j));
			chk[i][j]=0;
		}
	}
	
	printf("%d",ans);
	
	return 0;
}
