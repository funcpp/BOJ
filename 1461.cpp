#include <bits/stdc++.h>
using namespace std;

int N,M;
int calc(vector<int> v, bool back){
	int ret = 0, idx = 0;
	if(!back){
		if(v.size()%M){
			idx=v.size()%M;
			ret+=v[idx-1]*2;
		}
	}
	while(idx<v.size()){
		if(idx+M>= v.size()){
			if(back) ret+= v.back()*2;
			else ret += v.back();
			idx+=M;
		}
		else{
			idx+=M;
			ret += v[idx-1]*2;
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d",&N,&M);
	vector<int> p,n;
	for(int i=0;i<N;i++){
		int t;
		scanf("%d",&t);
		if(t>0) p.push_back(t);
		else n.push_back(-t);
	}
	
	sort(p.begin(), p.end());
	sort(n.begin(), n.end());
	
	if(p.back() > n.back()){
		printf("%d", calc(p,false) + calc(n,true));
	}
	else{
		printf("%d", calc(p,true) + calc(n,false));
	}
	
	return 0;
}
