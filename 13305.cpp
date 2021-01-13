#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	long long int dist[N+5]={0,};
	long long int oil[N+5]={0,};
	
	for(int i=0;i<N-1;i++){
		scanf("%lld",dist+i);
	}
	for(int i=0;i<N;i++){
		scanf("%lld",oil+i);
	}
	
	long long int ans = 0;
	long long int minoil = oil[0];
	
	for(int i=0;i<N-1;i++){
		minoil = min(minoil, oil[i]);
		ans += minoil*dist[i];
	}
	printf("%lld",ans);
	
	return 0;
}
