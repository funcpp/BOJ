#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N, ans=0;
	scanf("%d",&N);
	for(int i=0,a,b;i<N;i++)
	{
		scanf("%d %d",&a,&b);
		ans+=(b-(b/a)*a);
	}
	printf("%d",ans);
	return 0;
}
