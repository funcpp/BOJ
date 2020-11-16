#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	vector<int> H,P;
	char str[20005]={0,};
	scanf("%s",str);
	for(int i=0;i<N;i++){
		if(str[i]=='H')H.push_back(i);
		else if(str[i]=='P')P.push_back(i);
	}
	
	auto pit = P.begin();
	auto hit = H.begin();
	int ans = 0;
	while(pit!=P.end() && hit!=H.end()){
		int dist =  abs(*pit - *hit);
		if(dist <= K){
			hit++;
			pit++;
			ans++;
		}else{
			if(*pit>*hit)
				hit++;
			else
				pit++;
		}
	}
	printf("%d",ans);
	return 0;
}
