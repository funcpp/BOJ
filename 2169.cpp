#include<bits/stdc++.h>
using namespace std;
int arr[1005][1005];
int dp[1005][1005][3];
int chk[1005][1005];
int N,M;

int f(int x, int y, int d)
{
	if(x==N-1 && y==M-1){
		return arr[x][y];
	}
	
	int &ret = dp[x][y][d];
	//printf("%d %d %d\n",x,y,d);
	if(ret != 0x7f7f7f7f) return ret;
	
	chk[x][y]=true;
	
	int p1=-100000,p2=-100000,p3=-100000;
	
	if(y!=0 && !chk[x][y-1])
		p1=f(x,y-1,0);
	
	if(x!=N-1 && !chk[x+1][y])
		p2=f(x+1,y,1);	
	
	if(y!=M-1 && !chk[x][y+1])
		p3=f(x,y+1,2);
	
	chk[x][y]=false;
	
	ret = arr[x][y]+max(p3,max(p1,p2));
	return ret;
}

int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&arr[i][j]);
			for(int k=0;k<3;k++) dp[i][j][k]=0x7f7f7f7f;
		}
	}
	
	printf("%d",f(0,0,0));
	return 0;
}
