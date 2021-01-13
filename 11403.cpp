#include<bits/stdc++.h>
using namespace std;
int arr[105][105]={0,};
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	for(int j=0;j<N;j++){
		for(int i=0;i<N;i++){
			for(int k=0;k<N;k++){
				if(arr[i][j] && arr[j][k]) arr[i][k]=1;
			}
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
