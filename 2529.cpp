#include<bits/stdc++.h>
using namespace std;
int K;

int chk[20];

int bdh[20];

bool c(int* num){
	for(int i=0;i<K;i++){
		if(bdh[i]=='<' && num[i] > num[i+1]) return false;
		else if(bdh[i]=='>' && num[i] < num[i+1]) return false;
	}
	return true;
}

int amax, amin=0x7f7f7f7f;
string smax, smin;
void f(int num[15], int cnt)
{
	if(cnt==K+1){
		if(c(num)){
			int nn = 0;
			string ss="";
			for(int i=0;i<K+1;i++){
				nn = nn*10+num[i];
				ss = ss+to_string(num[i]);
			}
			if(amax<nn){
				nn=amax;
				smax=ss;
			}
			if(nn<amin){
				amin=nn;
				smin=ss;
			}
		}
		return;
	}
	
	for(int i=0;i<10;i++){
		if(!chk[i]){
			chk[i]=1;
			num[cnt]=i;
			f(num,cnt+1);
			num[cnt]=0;
			chk[i]=0;
		}
	}
	
	return;
}

int main()
{
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		scanf(" %c",&bdh[i]);
	}
	
	int num[15]={0,};
	f(num,0);
	
	cout<<smax<<endl<<smin;
	return 0;
}
