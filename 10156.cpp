#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,n,m;
	scanf("%d %d %d",&k,&n,&m);
	printf("%d",max(0,k*n-m));
}
