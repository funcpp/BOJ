#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[3]={0,};
	int c[7]={0,};
	int mc=0, ma=0, mca=0;
	for(int i=0;i<3;i++){
		scanf("%d",a+i);
		c[a[i]]++;
		if(mc<c[a[i]]){
			mc=c[a[i]];
			mca=a[i];
		}
		ma=max(ma,a[i]);
	}
	if(mc==1) printf("%d",ma*100);
	else if(mc==2) printf("%d",1000+mca*100);
	else if(mc==3) printf("%d",10000+mca*1000);
	return 0;
}
