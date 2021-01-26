#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=0,a;i<5;i++){
		scanf("%d",&a);
		if(a==n) ans++;
	}
	printf("%d",ans);
	return 0;
}
