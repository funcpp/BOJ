#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b) : a;}
int main(){
	int N, a[123123]={0,}; vector<int> g;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",a+i);
	}
	sort(a,a+N);
	for(int i=1;i<N;i++){
		g.push_back(a[i]-a[i-1]);
	}
	int mg=0x7f7f7f7f;
	for(int i=1;i<N;i++){
		mg=min(mg,gcd(g[i-1],g[i]));
	}
	int ag=0;
	for(int i=0;i<N-1;i++){
		if(g[i]!=mg){
			ag+=(g[i]/mg)-1;
		}
	}
	printf("%d",ag);
	return 0;
}
