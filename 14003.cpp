#include <bits/stdc++.h>
using namespace std;
#define u64 long long int

vector<u64> A, L;
int main()
{
	int N;
	scanf("%d",&N);
	A=vector<u64>(N+1);
	L=vector<u64>(N+1);
	vector<pair<u64, u64> > ans = vector<pair<u64, u64> >(N+1);
	
	for(int i=0;i<N;i++){
		scanf("%lld",&A[i]);
	}
	
	int idx=0;
	L[0]=A[0];
	ans[0].second=A[0];
	
	for(int i=1;i<N;i++){
		
		if(L[idx]<A[i]){
			idx++;
			L[idx]=A[i];
			ans[i] = {idx, A[i]};
		}
		else
		{
			int _idx = lower_bound(L.begin(), L.begin()+idx, A[i]) - L.begin();
			L[_idx]=A[i];
			ans[i] = {_idx, A[i]};
		}
	}
	
	printf("%d\n",idx+1);
	
	vector<u64> LIS;
	for(int i=N-1;i>=0;i--){
		if(ans[i].first == idx){
			LIS.push_back(ans[i].second);
			idx--;
		}
	}

	while(LIS.size())
	{
		printf("%lld ",LIS.back());
		LIS.pop_back();
	}

	return 0;
}
