#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,P,Q;
	scanf("%d %d",&N,&P);
	unordered_map<int,int> m;
	Q=N;
	int A=1;
	while(true){
		Q = (Q*N)%P;
		A++;
		if(m[Q]){
			printf("%d",A-m[Q]);
			break;
		}
		m[Q]=A;
	}
	return 0;
}
