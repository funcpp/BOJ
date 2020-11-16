#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define piii pair<int, pii>

int N;
int arr[55][55];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main()
{
	scanf("%d",&N);
	
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		
		for(int j=0;j<N;j++){
			arr[i][j] = s[j]-'0';
		}
	}
	
	priority_queue<piii> pq;
	pq.push({0,{0,0}});
	int ans[55][55] = {0,};
	memset(ans, 0x7f7f7f7f, sizeof(ans));
	
	ans[0][0] = 0;
	
	while(!pq.empty()) {
		piii top = pq.top(); pq.pop();
		int cost = -top.first;
		int x = top.second.first;
		int y = top.second.second;
		
		if(cost > ans[x][y]) continue;
		
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx>=0 && nx<N && ny>=0 && ny<N){
				int ncost = arr[nx][ny]==0?cost+1:cost;
				
				if(ncost < ans[nx][ny]){
					ans[nx][ny]=ncost;
					pq.push({-ncost, {nx, ny}});
				}
			}
		}
	}
	
	printf("%d",ans[N-1][N-1]);
	
	return 0;
}
