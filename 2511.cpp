#include<bits/stdc++.h>
using namespace std;
int main()
{
	int A[15]={0,}, B[15]={0,}, a=0,b=0, res=0;
	for(int i=0;i<10;i++) scanf("%d",A+i);
	for(int i=0;i<10;i++) scanf("%d",B+i);
	for(int i=0;i<10;i++){
		if(A[i]==B[i]){
			a++;
			b++;
		}
		else
		{
			if(A[i]>B[i]){
				a+=3;
				res=1;
			}
			else{
				b+=3;
				res=2;
			}
		}
	}

	printf("%d %d\n",a,b);
	printf("%c",a>b?'A':a==b?res==0?'D':res==1?'A':'B':'B');
	return 0;
}
