#include <bits/stdc++.h>
using namespace std;

int N,M;
int calc(priority_queue<int> pq, bool back){
	int ret = 0;
	if(!pq.size()) return ret;
	
	ret += back ? pq.top() * 2  : pq.top(); pq.pop();
	for(int i=0;i<M-1;i++){
		if(pq.empty()) break;
		pq.pop();
	}
	
	while(pq.size()){
		ret += pq.top() * 2;
		pq.pop();
		
		for(int i=0;i<M-1;i++){
			if(pq.empty()) break;
			pq.pop();
		}
	}
	
	return ret;
}

int main()
{
	scanf("%d %d",&N,&M);
	priority_queue<int> p,n;
	for(int i=0;i<N;i++){
		int t;
		scanf("%d",&t);
		if(t>0) p.push(t);
		else n.push(-t);
	}
	int pTop = p.size() ? p.top() : 0;
	int nTop = n.size() ? n.top() : 0;
	
	if(pTop > nTop){
		printf("%d", calc(p,false) + calc(n,true));
	}
	else{
		printf("%d", calc(p,true) + calc(n,false));
	}
	
	return 0;
}
