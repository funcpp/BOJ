#include<bits/stdc++.h>
using namespace std;
struct st{
	int a,b,c;
};
int main(){
	int N;
	scanf("%d",&N);
	st s[N+1];
	for(int i=0;i<N;i++){
		scanf("%d %d %d",&s[i].a, &s[i].b, &s[i].c);
	}
	sort(s, s+N, [&](st a, st b) -> bool{return a.c>b.c;});
	unordered_map<int, int> m;
	int c=0;
	for(int i=0;i<N;i++){
		if(m[s[i].a]<2){
			m[s[i].a]++;
			printf("%d %d\n",s[i].a,s[i].b);
			c++;
		}
		if(c==3) break;
	}
}
