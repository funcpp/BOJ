#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,t;
vector<int> v, w;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&t);
		v.push_back(-t);
	}
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		scanf("%d",&t);
		w.push_back(-t);
	}
	
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	
	t=0;
	while(w.size()){
		size_t rsize = w.size();
		for(auto it = v.begin(); w.size(), it!=v.end(); it++){
			auto it2  = lower_bound(w.begin(), w.end(), *it);
			if(it2 != w.end()){
				w.erase(it2);
			}
		}
		if(w.size() == rsize){
			printf("-1"); return 0;
		}
		t++;
	}
	printf("%d",t);
}
