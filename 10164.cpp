#include<bits/stdc++.h>
using namespace std;
unsigned long long int f(unsigned long long N)
{
	if(N<=1) return 1;
	return N * f(N-1);	
}

unsigned long long int aaa(unsigned long long int N, unsigned long long int M)
{
	unsigned long long ans = 1;
	unsigned long long h = N-1, w = M-1;
	for(unsigned long long i = max(w,h)+1; i<=w+h;i++){
		ans*=i;
	}
	for(unsigned long long i=1;i<=min(w,h);i++) {
		ans/=i;
	}
	//printf("%llu",ans);
	return ans;
}

int main()
{
	int N,M,K;
	scanf("%d %d %d",&N,&M,&K);
	
	int ki=0,kj=0,cur=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(K==cur){
				ki=i;
				kj=j;
				cur=-1;
				break;
			}
			cur++;
		}
		if(cur==-1) break;
	}
	
	if(K)
	{
		//unsigned long long int c = f(ki);
		//unsigned long long int d = f(kj);
		//unsigned long long int a = f(ki+kj)/(c*d);
		//unsigned long long int h = f(N-1-ki);
		//unsigned long long int g = f(M-1-kj);
		//unsigned long long int b = f(N-ki+M-kj-1-1)/(h*g);
		//printf("%llu",a*b);
		printf("%llu",aaa(ki+1,kj+1) * aaa(N-ki,M-kj));
	}
	else
	{
		//unsigned long long int h = f(N-1);
		//unsigned long long int g = f(M-1);
		//unsigned long long int b = f(N+M-1-1)/(h?h:1)/(g?g:1);
		printf("%llu",aaa(N,M));
	}
	return 0;
}
