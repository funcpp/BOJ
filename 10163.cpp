#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[105][105]={0,};
	int N;
	scanf("%d",&N);
	for(int i=1,z,x,c,v;i<=N;i++){
		scanf("%d %d %d %d",&z,&x,&c,&v);
		for(int j=z;j<z+c;j++){
			for(int k=x;k<x+v;k++){
				a[j][k]=i;
			}
		}
	}
	
	int S[105]={0,};
	for(int i=0;i<=101;i++){
		for(int j=0;j<=101;j++){
			S[a[i][j]]++;
		}
	}
	for(int i=1;i<=N;i++){
		printf("%d\n",S[i]);
	}
	return 0;
}
