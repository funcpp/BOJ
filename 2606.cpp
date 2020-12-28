#include<bits/stdc++.h>
using namespace std;
int V,E;

int main()
{
	
	scanf("%d %d",&V,&E);
	
	vector<vector<int> > edge = vector<vector<int > >(V+5,vector<int>());
	for(int i=0;i<E;i++)
	{
		int A,B;
		scanf("%d %d",&A,&B);
		edge[A].push_back(B);
		edge[B].push_back(A);
	}
	
	int ans=0;
	int chk[105]={0,};
	
	auto d = [&](int idx, auto d) -> void
	{
		for(int nx : edge[idx]){
			if(!chk[nx]){
				chk[nx]=1;
				d(nx,d);
			}
		}	
	};
	
	chk[1]=1;
	d(1,d);
	
	for(int i=2;i<=100;i++){
		if(chk[i])ans++;
	}
	
	
	printf("%d",ans);
	
	return 0;
}
