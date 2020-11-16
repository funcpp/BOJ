#include<stdio.h>
#include<vector>
#include<queue>
#include<utility>
#include<unordered_map>
using namespace std;
int L,R,C;
int arr[35][35][35];
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

struct pos
{
	int x,y,z;	
};
int main()
{
	while(true){
		scanf("%d %d %d",&L,&R,&C);
		if(!L&&!R&&!C) break;
		pos S,E;
		for(int i=0;i<L;i++){
			for(int j=0;j<R;j++){
				char s[C+5]={0,};
				scanf("%s",s);
				
				for(int k=0;k<C;k++){
					arr[i][j][k] = s[k]=='#'?1:0;
					if(s[k]=='S') S={i,j,k};
					else if(s[k]=='E') E={i,j,k};
				}
			}
		}
		
		queue<pos> q;
		q.push(S);
		int chk[L+5][R+5][C+5]={0,};
		while(!q.empty()){
			pos frt = q.front(); q.pop();
			
			for(int i=0;i<6;i++){
				int nx = frt.x + dx[i];
				int ny = frt.y + dy[i];
				int nz = frt.z + dz[i];
				
				if(nx>=0&&nx<L&&ny>=0&&ny<R&&nz>=0&&nz<C&&!arr[nx][ny][nz]){
					if(!chk[nx][ny][nz] || chk[nx][ny][nz]>chk[frt.x][frt.y][frt.z]+1){
						chk[nx][ny][nz] = chk[frt.x][frt.y][frt.z]+1;
						q.push({nx,ny,nz});
					}
				}
			}
		}
		
		if(chk[E.x][E.y][E.z])
			printf("Escaped in %d minute(s).\n",chk[E.x][E.y][E.z]);
		else
			printf("Trapped!\n");
	}
}
