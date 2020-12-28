#include<bits/stdc++.h>
using namespace std;
#define u64 long long int
int N;
int arr[123][123];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
unordered_map<u64, bool> chk;

void f(int x, int y, bool idi)
{
	for(int i=0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(0<=nx&&nx<N&&0<=ny&&ny<N&&!chk.count((nx<<16)+ny)){
			if((!idi && arr[nx][ny]==arr[x][y]) || (idi && arr[nx][ny]%2 == arr[x][y]%2))
			{
				chk[(nx<<16)+ny]=true;
				f(nx,ny,idi);
			}
		}
	}
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		char s[N+5]={0,};
		scanf("%s",s);
		for(int j=0;j<N;j++){
			if(s[j]=='R') arr[i][j]=1;
			if(s[j]=='G') arr[i][j]=3;
			if(s[j]=='B') arr[i][j]=2;
		}
	}
	
	
	int a0=0,a1=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++){
			if(!chk.count((i<<16)+j)){
				chk[(i<<16)+j]=true;
				f(i,j, 0);
				a0++;
			}
		}
	}
	
	chk.clear();
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++){
			if(!chk.count((i<<16)+j)){
				chk[(i<<16)+j]=true;
				f(i,j, 1);
				a1++;
			}
		}
	}
	
	printf("%d %d",a0,a1);
	
	return 0;
}
