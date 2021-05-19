#include<bits/stdc++.h>
using namespace std;

int main()
{
	char S[12]={0,};
	scanf("%s",S);
	
	for(int i=0;S[i]!='\0';i++) {
		int count=0,t=S[i];
		while(S[i]){
			count+=S[i]%10;
			S[i]/=10;
		}
		for(int j=0;j<count;j++) printf("%c",t);
		printf("\n");
	}
	
	return 0;
}
