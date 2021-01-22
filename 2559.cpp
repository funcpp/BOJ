#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	int arr[N+5]={0,};
	for(int i=0;i<N;i++){
		scanf("%d",arr+i);
	}
	long long int a = 0;
	for(int i=0;i<K;i++){
		a+=arr[i];
	}
	long long int ans = a;
	for(int i=K;i<N;i++){
		a-=arr[i-K];
		a+=arr[i];
		ans=max(ans,a);
	}
	printf("%d",ans);
	return 0;
}
