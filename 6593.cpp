#include <stdio.h>
#include <memory.h>

int L,R,C;
int map[31][31][31];
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
int chk[31][31][31];
int save[31][31][31];
int ans=0;

struct Point
{
	int x,y,z;
};

void dfs(int x, int y, int z, int cnt)
{
	if(save[x][y][z] !=0 && save[x][y][z] < cnt) return;
	else save[x][y][z]=cnt;
	
	for(int i=0; i<6; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		int nz = z + dz[i];
		
		if(nx>=0 && nx<L && ny>=0 && ny<R && nz>=0 && nz<C && !chk[nx][ny][nz])
		{
			if(map[nx][ny][nz]==0 || map[nx][ny][nz]==3)
			{
				//chk[nx][ny][nz]=1;
				dfs(nx,ny,nz,cnt+1);
				//chk[nx][ny][nz]=0;
			}
		}
	}
	
	return;
}

int main()
{
	while(true)
	{
		ans=0;
		scanf("%d %d %d",&L,&R,&C);
		if(L==0 && R==0 && C==0) break;
		Point st, fi;
		for(int i=0; i<L; i++)
		{
			for(int j=0; j<R; j++)
			{
				char s[C+1];
				scanf("%s",s);
				for(int k=0; k<C; k++)
				{
					if(s[k]=='S')
					{
						st={i,j,k};
						map[i][j][k]=2;
					}
					else if(s[k]=='.') map[i][j][k]=0;
					else if(s[k]=='#') map[i][j][k]=1;
					else if(s[k]=='E')
					{
						fi={i,j,k};
						map[i][j][k]=3;
					}
				}
			}
		}
		
		//chk[st.x][st.y][st.z]=1;
		dfs(st.x,st.y,st.z,0);
		//chk[st.x][st.y][st.z]=0;
		
		ans = save[fi.x][fi.y][fi.z];
		
		if(ans==0)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n",ans);
			
		memset(save,0,sizeof(save));
		memset(map,0,sizeof(map));
		memset(chk,0,sizeof(chk));
	}
	return 0;
}
