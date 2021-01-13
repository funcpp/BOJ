#include<bits/stdc++.h>
using namespace std;
#define uint64_t long long int
int main()
{
	int K,C;
	scanf("%d %d",&K,&C);
	
	for(int i=0,M,N;i<C;i++){
		scanf("%d %d",&M,&N);
		if(M==N){
			printf("1\n");
			continue;
		}
		
		int rm = max(M,N);
		int ps = K-rm;
		if(M>N)
			printf("%d\n",M-N<=2+ps?1:0);
		else
			printf("%d\n",N-M<=1+ps?1:0);
	}	
	return 0;
}
