#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	
	unordered_map<int, bool> chk;
	
	queue<pair<int, int> > q;
	q.push({N,0});
	
	while(!q.empty())
	{
		auto frt = q.front(); q.pop();
		
		if(frt.first == K) {
			printf("%d",frt.second);
			return 0;
		}
		
		if(frt.first*2 <= 100000 && !chk.count(frt.first*2)){
			chk[frt.first*2]=true;
			q.push({frt.first*2, frt.second+1});
		}
		
		if(frt.first+1 <= 100000 && !chk.count(frt.first+1)){
			chk[frt.first+1]=true;
			q.push({frt.first+1, frt.second+1});
		}
		
		if(0<= frt.first-1 && !chk.count(frt.first-1)){
			chk[frt.first-1]=true;
			q.push({frt.first-1, frt.second+1});
		}
	}
	
	return 0;
}
