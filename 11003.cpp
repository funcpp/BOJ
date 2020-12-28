#include <bits/stdc++.h>
using namespace std;
#define u64 long long int 
deque<pair<int ,int >> v;
int A[5000005];

int main()
{
	int N,L;
	scanf("%d %d",&N,&L);
	for(int i=0;i<N;i++){
		scanf("%d",A+i);
	}
	
	for(int i=0;i<N;i++){
		if(v.size() && (v.front().second<i-L+1)) v.pop_front();
		while(v.size() && (v.back().first)>A[i]) v.pop_back();
		
		v.push_back({A[i],i});
		
		printf("%d ",(v.front().first));
		
	}
	return 0;
}
