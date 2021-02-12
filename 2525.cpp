#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int d=a*60+b+c;
	d%=24*60;
	printf("%d %d",d/60, d%60);
	return 0;
}
