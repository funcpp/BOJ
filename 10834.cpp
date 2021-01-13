#include<bits/stdc++.h>
using namespace std;
int main()
{
	int M;
	scanf("%d",&M);
	int next=0, spin=0;
	for(int i=0,a,b,c;i<M;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(!i)
			next=b;
		else
			next = (next/a)*b;
		spin^=c;
	}
	printf("%d %d",spin,next);
	return 0;
}
