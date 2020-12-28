#include<bits/stdc++.h>
using namespace std;
#define u64 unsigned long long int
bool chk[4000005];
vector<u64> ps;

int main()
{
	u64 N;
	scanf("%llu",&N);
	
	vector<int> pr;
	for(int i=2;i<=4000000;i++){
		if(!chk[i]){
			pr.push_back(i);
			for(int j=i;j<=4000000;j+=i){
				chk[j]=1;
			}
		}
	}
	
	ps.push_back(0);
	ps.push_back(pr[0]);
	
	for(int i=1;i<pr.size();i++){
		ps.push_back(pr[i] + ps.back());
	}
	
	//printf("%d %d %d %d %d %d",ps[0],ps[1],ps[2],ps[3],ps[4],ps[5]);
	
	int ans=0;
	
	int s=0,e=1;
	while(true)
	{
		if(e==ps.size()) break;
		
		u64 cur = ps[e]-ps[s];
		if(cur < N){
			e++;
			continue;
		}
		
		if(N==cur) ans++;
		
		s++;
	}
	
	printf("%d",ans);
	return 0;
}
