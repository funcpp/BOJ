#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	if(K>N/2) K =  N-K;
	long long ans = 1;
	for(int i=0;i<K;i++){
		ans*=N-i;
	}
	for(int i=1;i<=K;i++){
		ans/=i;
	}
	printf("%lld",ans);
	return 0;
}
