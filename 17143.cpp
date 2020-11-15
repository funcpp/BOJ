#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

struct shark {
	int r=0, c=0, s=0,d=0,z=0;
	shark() {};
	shark(int R,int C,int S,int D,int Z) : r(R), c(C), s(S), d(D), z(Z) {};
};
vector<pii> shv;

int R,C,M;
shark arr[105][105];

int main()
{
	scanf("%d %d %d",&R,&C,&M);
	for(int i=0;i<M;i++){
		int r,c,s,d,z;
		
		scanf("%d %d %d %d %d",&r,&c,&s,&d,&z);
		arr[r-1][c-1]={r-1,c-1,s,d-1,z};
		shv.push_back({r-1,c-1});
	}
	int ans = 0;
	for(int i=0;i<C;i++){
		
		/*
		printf("cur : %d ans : %d\n",i,ans);
		for(int x=0;x<R;x++){
			for(int y=0;y<C;y++){
				printf("%d ",arr[x][y].z);
			}
			printf("\n");
		}
		printf("\n");
		*/
		
		pii kill={-1,-1};
		for(int j=0;j<R;j++){
			if(arr[j][i].z) {
				ans += arr[j][i].z;
				arr[j][i]={j,i,0,0,0};
				kill={j,i};
				break;
			}
		}
		
		vector<shark> nshv;
		for(pii sh : shv){
			if(sh.first == kill.first && sh.second == kill.second) continue;
			
			shark& osh = arr[sh.first][sh.second];
			
			int mcnt = 0;
			if(osh.d & 2) mcnt = osh.s % (C*2-2);
			else mcnt = osh.s % (R*2-2);
			
			int nx=sh.first, ny=sh.second;
			for(int j=0; j<mcnt;j++){
				nx += dx[osh.d];
				ny += dy[osh.d];
				
				if(nx<0 || nx>=R || ny<0 || ny>=C){
					osh.d^=1;
					nx += dx[osh.d]*2;
					ny += dy[osh.d]*2;
				}
			}
			
			nshv.push_back(shark(nx,ny, osh.s, osh.d,osh.z));
			osh = {0,0,0,0,0};
		}
		shv.clear();
		for(shark sh : nshv){
			if(arr[sh.r][sh.c].z < sh.z)
			{
				if(!arr[sh.r][sh.c].z){
					shv.push_back({sh.r,sh.c});
				}
				arr[sh.r][sh.c] = sh;
			}
		}
	}
	
	printf("%d",ans);
	
	return 0;
}
