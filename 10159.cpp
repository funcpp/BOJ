#include <stdio.h>
int floyd[105][105];
int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	
	for(int i=0,a,b; i<M; i++){
		scanf("%d %d",&a,&b);
		floyd[a][b]=1;
		floyd[b][a]-1;
	}
	
	for(int j=1; j<=N; j++)
	for(int i=1; i<=N; i++)
	for(int k=1; k<=N; k++){
		if(floyd[i][k]==0){
			if(floyd[i][j]==1 && floyd[j][k]==1) floyd[i][k]=1;
			else if(floyd[i][j]==-1 && floyd[j][k]==-1) floyd[i][k]=-1;
		}
	}
	
	for(int i=1; i<=N; i++){
		int cnt=0;
		for(int j=1; j<=N; j++){
			if(i==j) continue;
			if(!floyd[i][j] && !floyd[j][i]) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
