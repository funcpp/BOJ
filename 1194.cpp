#include <bits/stdc++.h>
using namespace std;

#define u64 long long int

int N,M;
int arr[55][55];
u64 minsik;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
unordered_map<u64, bool> chk[64];

// a b c d e f
struct Data
{
	u64 pos;
	int count=0;
	u64 key = 0x000000;
	Data(u64 P) : pos(P){};
};

int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		char s[N+5]={0,};
		scanf("%s",s);
		for(int j=0;j<M;j++){
			arr[i][j]=s[j];
			
			if(s[j]=='0'){
				arr[i][j]='.';
				minsik = (i<<16)+j;
			}
		}
	}
	
	Data st(minsik);
	
	queue<Data> q;
	q.push(st);
	while(q.size())
	{
		Data frt = q.front(); q.pop();
		
		int x = frt.pos>>16;
		int y = frt.pos&0xFFFF;
		int key = frt.key;
		
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(0<=nx&&nx<N&&0<=ny&&ny<M&& chk[frt.key][(nx<<16)+ny]!=true){
				
				Data nd((nx<<16)+ny);
				nd.count=frt.count+1;
				nd.key = key;
				
				if(arr[nx][ny]=='.')
				{
					chk[key][(nx<<16)+ny]=true;
					
					q.push(nd);
				}
				else if('a'<=arr[nx][ny] && arr[nx][ny] <='f'){
					nd.key |= (1 << arr[nx][ny]-'A');
					
					if(chk[nd.key][(nx<<16)+ny]!=true){
						chk[key][(nx<<16)+ny]=true;
						chk[nd.key][(nx<<16)+ny]=true;
						
						q.push(nd);
					}
				}
				else if('A'<=arr[nx][ny] && arr[nx][ny] <= 'F' && (nd.key & (1 << arr[nx][ny]-'A'))){
					chk[frt.key][(nx<<16)+ny]=true;
					
					q.push(nd);
				}
				else if(arr[nx][ny]=='1'){
					printf("%d",frt.count+1);
					return 0;
				}
			}
		}
	}
	
	printf("-1");
	
	return 0;
}
