#include<bits/stdc++.h>
using namespace std;

int prt[100005];

int find(int  x){
	if(x==prt[x]) return x;
	return prt[x] = find(prt[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	
	prt[x]=y;
}

int main()
{
	int G,P,ans=0;
	scanf("%d",&G);
	scanf("%d",&P);
	
	for(int i=0;i<G+5;++i) prt[i]=i;

	bool done=false;	
	for(int i=0;i<P;i++){
		int a;
		scanf("%d",&a);
		
		if(!done){
			int p = find(a);
			if(!p) done=true;
			else
			{
				ans++;
				merge(p,p-1);	
			}
		}
	}
	
	printf("%d",ans);
	
	
	return 0;
}
