#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	
	int floyd[105][105]={0,};
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			floyd[i][j]=0x7f7f7f7f;
			if(i==j) floyd[i][j]=0;
		}
	}
	
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		
		floyd[a][b]=min(floyd[a][b],c);
	}
	
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				if(floyd[i][j]!=0x7f7f7f7f && floyd[j][k]!=0x7f7f7f7f){
					floyd[i][k]=min(floyd[i][k],floyd[i][j]+floyd[j][k]);
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",floyd[i][j]==0x7f7f7f7f?0:floyd[i][j]);
		}
		printf("\n");
	}
}
