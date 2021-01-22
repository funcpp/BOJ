#include<bits/stdc++.h>
using namespace std;
#define piii pair<pair<int,int>,int>
int main()
{
	int N,C,M;
	scanf("%d %d %d",&N,&C,&M);
	
	vector<piii> arr;
	
	for(int i=0,a,b,c;i<M;i++){
		scanf("%d %d %d",&a,&b,&c);
		arr.push_back({{a,b},c});
	}
	
	sort(arr.begin(), arr.end(), [](piii a, piii b)->bool{
	if(a.first.second<b.first.second) return 1;
	else if(a.first.second == b.first.second) if(a.first.first==b.first.first) return 1;
	return 0;
	});
	
	int ans=0;
	int cur[N+5]={0,};
	for(int i=0;i<M;i++){
		int t=0;
		for(int j=arr[i].first.first;j<arr[i].first.second;j++)
			t=max(t,cur[j]);
		
		int p=min(arr[i].second , C-t);
		ans+=p;
		
		for(int j=arr[i].first.first;j<arr[i].first.second;j++)
			cur[j]+=p;
	}
	
	printf("%d",ans);
	
	return 0;
}
