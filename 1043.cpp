#include<stdio.h>
#include<unordered_map>
using namespace std;
int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	unordered_map<int, bool> m;
	int t;
	scanf("%d",&t);
	for(int i=0,a;i<t;i++){
		scanf("%d",&a);
		m[a]=true;
	}
	
	int ans=0;
	for(int i=0,t;i<M;i++){
		scanf("%d",&t);
		bool b=false;
		for(int j=0,a;j<t;j++){
			scanf("%d",&a);
			if(m.count(a)){
				b=true;
			}
		}
		if(!b)ans++;
	}
	printf("%d",ans);
	return 0;
}
