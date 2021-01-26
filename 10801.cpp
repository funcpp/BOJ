#include<bits/stdc++.h>
using namespace std;
int main()
{
	int A[15]={0,},B[15]={0,};
	for(int i=0;i<10;i++)scanf("%d",A+i);	 
	for(int i=0;i<10;i++)scanf("%d",B+i);
	
	int a=0,b=0;
	for(int i=0;i<10;i++){
		if(A[i]<B[i])b++;
		else if(A[i]>B[i])a++;
	}
	printf("%c",a==b?'D':a>b?'A':'B');
	
	return 0;
}
