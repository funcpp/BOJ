#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	if(T%10){
		printf("-1");
		return 0;
	}
	
	int A = T/300;
	T -= A*300;
	
	int B = T/60;
	T -= B*60;
	
	int C = T/10;
	T -= C*10;
	
	printf("%d %d %d",A,B,C);
	
	return 0;
}
