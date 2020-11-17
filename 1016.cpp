#include <stdio.h>
#include <vector>
using namespace std;
int main(){
	long long min, max, ans=0;
	scanf("%lld %lld",&min,&max);
	
	vector<bool> d = vector<bool>(1000005,0);
	for(long long i=2;i*i<=max;i++){
		long long x = min / (i*i);
		if(min % (i*i)) x++;
		for(long long j=x*i*i;j<=max;j+=i*i){
			d[j-min]=1;
		}
	}
	for(long long i=min;i<=max;i++){
		if(!d[i-min]) ans++;
	}
	printf("%lld",ans);
	return 0;
}
