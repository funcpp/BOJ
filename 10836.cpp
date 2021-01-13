#include<bits/stdc++.h>
using namespace std;
int mp[800][800];
int tt[800][800];

int main()
{
	int M,N;
	scanf("%d %d",&M,&N);
	
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			mp[i][j]=1;
		}
	}
	
	for(int x=0;x<N;x++){
		int arr[M*2+5]={0,};
		for(int j=0;j<M*2-1;j++){
			scanf("%d",&arr[j]);
		}
		for(int i=0;i<M;i++){
			for(int j=0;j<M;j++){
				tt[i][j]=mp[i][j];
			}
		}
		for(int i=0;i<M;i++){
			mp[i][0]+=arr[M-1-i];
		}
		for(int i=1;i<M;i++){
			mp[0][i]+=arr[M-1+i];
		}
		for(int i=1;i<M;i++){
			for(int j=1;j<M;j++){
				mp[i][j]+=max(max(mp[i-1][j]-tt[i-1][j],mp[i-1][j-1]-tt[i-1][j-1]),mp[i][j-1]-tt[i][j-1]);
			}
		}
	}
	
	printf("\n");
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			printf("%d ",mp[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
