#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

int main()
{
	int N,M;
	scanf("%d %d",&N, &M);
	
	int floyd[105][105]={0,};
	
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++){
			floyd[i][j] = i==j?0:INF;
		}
	}
	for(int i=0,u,v;i<M;i++) {
		scanf("%d %d",&u,&v); u--;v--;
		floyd[u][v]=1;
		floyd[v][u]=-1;
	}
	
	for(int j=0;j<N;j++) {
		for(int i=0;i<N;i++) {
			for(int k=0;k<N;k++){
				if(floyd[i][j]==1&&floyd[j][k]==1) floyd[i][k]=1;
				if(floyd[i][j]==-1&&floyd[j][k]==-1) floyd[i][k]=-1;
			}
		}
	}
	
	for(int i=0, ans=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(floyd[i][j]==INF && floyd[j][i]==INF) ans++;
		}
		printf("%d\n",ans); ans=0;
	}
	
	return 0;
}
