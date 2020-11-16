#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int N,M,K,A;
map<string, int> m;

int main(){
	scanf("%d %d",&N,&M);
	vector<string> v = vector<string>(N,"");
	for(int i=0;i<N;i++){
		cin>>v[i];
	}
	scanf("%d",&K);
	
	for(int i=0;i<N;i++){
		size_t z = 0;
		for(int j=0;j<M;j++){
			if(v[i][j]=='0') z++;
		}
		if(z<=K && (K-z)%2==0){
			A=max(A,++m[v[i]]);
		}
	}
	printf("%d",A);
	
	return 0;
}
