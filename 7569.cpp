#include <bits/stdc++.h>
using namespace std;
int M,N,H;
int arr[200][200][200];

int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

int count()
{
	int cnt=0;
	for(int k=0;k<H;k++)
	for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
	if(arr[i][j][k]==0) cnt++;
	
	return cnt;
}

int main()
{
	scanf("%d %d %d",&M,&N,&H);
	
	for(int i=0;i<H;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++){
				scanf("%d",&arr[j][k][i]);
			}
		}
	}
	
	int ans=0;
	queue<pair<pair<int,int>,pair<int,int>>> q; //{{x,y},{z,c}}
	
	for(int k=0;k<H;k++)
	for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
	if(arr[i][j][k]==1) q.push({{i,j},{k,0}});
	
	while(!q.empty()){
		pair<pair<int,int>,pair<int,int>> frt = q.front(); q.pop();
		int x = frt.first.first;
		int y = frt.first.second;
		int z = frt.second.first;
		int c = frt.second.second;
		ans=max(ans,c);
		for(int i=0;i<6;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			
			if(0<=nx&&nx<N&&0<=ny&&ny<M&&0<=nz&&nz<H){
				if(arr[nx][ny][nz]==0){
					arr[nx][ny][nz]=1;
					q.push({{nx,ny},{nz,c+1}});
				}
			}
		}
	}
	
	if(count()){
		printf("-1");
		return 0;	
	}
	
	printf("%d",ans);
	
	return 0;
}
