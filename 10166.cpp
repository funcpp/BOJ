#include<bits/stdc++.h>
using namespace std;
int main()
{
	auto gcd = [](int a, int b, auto func)->int
	{
		return b?func(b,a%b,func):a;	
	};
	
	int D1,D2;
	scanf("%d %d",&D1,&D2);
	unordered_map<int, bool> ht;
	int ans=1;
	for(int i=D1;i<=D2;i++){
		vector<int> v;
		for(int q=0; q<i;q++){
			if(q==0) continue;
			
			int a=i,b=q,g=gcd(a,b,gcd);
			a/=g;
			b/=g;
			
			if(!ht.count(a))
			{
				ans++;
				v.push_back(a);
			}
		}
		for(int z:v)ht[z]=1;
	}
	printf("%d",ans);
	
	return 0;
}
