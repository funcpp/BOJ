#include<bits/stdc++.h>
using namespace std;

struct _st
{
	int idx, g,s,b;	
	
	bool operator<(const struct _st& A){
		if(g==A.g) if(s==A.s) return b>A.b; else return s>A.s; else return g>A.g;
	}
	
};

int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	_st st[N+5];
	for(int i=0;i<N;i++){
		scanf("%d %d %d %d",&st[i].idx, &st[i].g, &st[i].s, &st[i].b);
	}
	
	sort(st,st+N);
	
	int rank=1, br =1;
	_st p=st[0];
	if(p.idx==K){
		printf("1");
		return 0;
	}
	
	for(int i=1;i<N;i++){
		//printf("%d %d %d %d\n",st[i].idx, st[i].g, st[i].s, st[i].b);
		if(st[i].g!=p.g||st[i].s!=p.s||st[i].b!=p.b){
			rank+=br;
			br=1;
		}
		else {
			br++;
		}
		
		if(st[i].idx==K){
			printf("%d",rank); break;
		}
		p=st[i];
	}
	
	return 0;
}
