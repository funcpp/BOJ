#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	int e=a*60*60+b*60+c+d;
	e%=24*60*60;
	printf("%d %d %d",e/3600,(e%3600)/60, (e%3600)%60);
	return 0;
}
