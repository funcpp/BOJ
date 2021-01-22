#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	int idx[N+5]={0,};
	int arr[N+5]={0,}, arr3[N+5]={0,}, arr2[N+5]={0,};
	for(int i=1,t;i<=N;i++){
		scanf("%d",idx+i);
		arr2[idx[i]]=i;
	}
	vector<int> v;
	priority_queue<int> pq;
	for(int i=1,k;i<=N;i++){
		scanf("%d",&k);
		int c=arr2[k];
		if(!v.size() || v.back() < c){
			if(!v.size()) arr3[c]=-1;
			else arr3[c]=v.back();
			v.push_back(c);
		}
		else {
			int _idx = lower_bound(v.begin(),v.end(),c)-v.begin();
			v[_idx]=c;
			arr3[c]=_idx?v[_idx-1]:-1;
		}
	}
	int _idx=v.back();
	printf("%d\n",v.size());
	while(_idx>0){
		pq.push(-1 * idx[_idx]);
		_idx=arr3[_idx];
	}
	while(pq.size()){
		printf("%d ",-1*pq.top());
		pq.pop();
	}
	return 0;
}
