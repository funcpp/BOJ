#include<bits/stdc++.h>
using namespace std;
#define u64 long long int

u64 baby;
u64 bsize = 2;
u64 beat;
int N;

vector<pair<u64,int> > food;
int arr[25][25];

u64 getd(u64 a, u64 b)
{
	return abs((a>>16) - (b>>16)) + abs((a&0xFFFF) - (b&0xFFFF));
}

u64 target;
u64 tDist;
unordered_map<u64, bool> chk;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
u64  _dist[25][25];
void getTarget(u64 pos){
	
	if(arr[pos>>16][pos&0xFFFF] && arr[pos>>16][pos&0xFFFF] < bsize){
		u64 _D = _dist[pos>>16][pos&0xFFFF];
		if(_D < tDist){
			tDist=_D;
			target=pos;
			
			//printf("%d %d\n",bsize,arr[pos>>16][pos&0xFFFF]);
		}
		else if(_D == tDist)
		{
			if(target>>16 > pos>>16){
				target=pos;
			}
			else if(target>>16 == pos>>16 && (target&0xFFFF) > (pos&0xFFFF)){
				target=pos;
			}
		}
		
		//printf("%d %d\n",bsize,arr[pos>>16][pos&0xFFFF]);
	}
	
	for(int i=0;i<4;i++){
		int nx = (pos>>16)+dx[i];
		int ny = (pos&0xFFFF)+dy[i];
		if(0<=nx&&nx<N&&0<=ny&&ny<N)
		if(arr[nx][ny]<=bsize && !chk.count((nx<<16)+ny)){
			chk[(nx<<16)+ny]=true;
			getTarget((nx<<16)+ny);
		}
	}
}


int main()
{
	scanf("%d",&N);
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&arr[i][j]);
			
			if(arr[i][j]==9){
				baby=(i<<16)+j;
			}
			else if(arr[i][j]){
				food.push_back({(i<<16)+j, arr[i][j]});	
			}
		}
	}
	
	int ans=0;
	while(true)
	{	
		target=-1;
		chk.clear();
		tDist =0x7f7f7f7f;
		chk[baby]=true;
		
		memset(_dist, 0, sizeof(_dist));
		queue<pair<u64, int> > q;
		q.push({baby,0});
		while(q.size()){
			auto frt = q.front(); q.pop();
			u64 pos = frt.first;
			u64 dst = frt.second;
			
			int x = pos>>16;
			int y = pos&0xFFFF;
			
			_dist[x][y]=dst;
			
			for(int i=0;i<4;i++){
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(0<=nx&&nx<N&&0<=ny&&ny<N)
				if(arr[nx][ny]<=bsize && !chk.count((nx<<16)+ny)){
					chk[(nx<<16)+ny]=true;
					q.push({(nx<<16)+ny, dst+1});
				}
			}
		}
		
		chk.clear();
		chk[baby]=true;
		getTarget(baby);
		
		if(target==-1) break;	
		
		arr[target>>16][target&0xFFFF]=9;
		arr[baby>>16][baby&0xFFFF]=0;
		baby=target;
		beat++;
		
		/*printf("\n");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
		printf("%d -> %d(%d)\n",ans,ans+tDist,bsize);
		*/
		
		if(beat==bsize){
			beat=0;
			bsize++;
			//printf("size up %d\n",bsize);
		}
		
		ans+=tDist;
	}
	
	printf("%d",ans);
	
	return 0;
}
