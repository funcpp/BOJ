#include<bits/stdc++.h>
using namespace std;
bool c(int n)
{
	int t=n;
	int a=0;
	while(n){
		a+=n%10;
		n/=10;
	}
	return !(t%a);
}
int main()
{
	int N;
	scanf("%d",&N);
	int ans=0;
	for(int i=1;i<=N;i++){
		if(c(i))ans++;
	}
	printf("%d",ans);
	return 0;
}
