#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	N -= N/60*60;
	//printf("%d\n",N);
	int x=6, y=8;
	
	for(int i=0;i<N;i++){
		x++;
		y++;
		x%=10;
		y%=12;
	}
	printf("%c%d",'A'+y,x);
	
	return 0;
}
