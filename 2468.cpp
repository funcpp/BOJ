#include<bits/stdc++.h>
using namespace std;
int N;
int arr[105][105];
map<pair<int, int>, bool> chk;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int x, int y, int h){
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(0<=nx&&nx<N&&0<=ny&&ny<N&&!chk[{nx,ny}]&&arr[nx][ny]>h){
			chk[{nx,ny}]=1;
			dfs(nx,ny,h);
		}
	}
}

int main()
{
	scanf("%d",&N);
	int low=0x7f7f7f7f, high=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&arr[i][j]);
			low=min(low,arr[i][j]);
			high=max(high,arr[i][j]);
		}
	}
	
	int ans = 0;
	for(int k=low;k<=high;k++){
		chk.clear();
		
		int cnt = 0;
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(!chk[{i,j}]&&arr[i][j]>k){
					chk[{i,j}]=1;
					dfs(i,j,k);
					cnt++;
				}
			}
		}
		
		ans=max(ans,cnt);
	}
	
	printf("%d",ans);
	
	return 0;
}
