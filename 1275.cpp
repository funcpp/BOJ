#include<bits/stdc++.h>
using namespace std;

#define u64 long long int

u64 arr[100005];
u64 tree[100005 *4];
u64 init(int node, int s, int e)
{
	if(s==e) return tree[node]=arr[s];
	int mid = (s+e)/2;
	return tree[node] = init(node*2, s,mid) + init(node*2+1,mid+1,e);
}

void update(int node, int s, int e, int idx, u64 diff)
{
	if(idx<s || e<idx) return;
	tree[node]+=diff;
	
	if(s!=e){
		int mid = (s+e)/2;
		update(node*2  , s,mid, idx, diff);
		update(node*2+1,mid+1,e,idx,diff);
	}
}

u64 sum(int node, int s, int e, int l, int r)
{
	if(r<s||e<l) return 0;
	if(l<=s&&e<=r) return tree[node];
	
	int mid = (s+e)/2;
	return sum(node*2, s,mid,l,r)+sum(node*2+1,mid+1,e,l,r);
}

int main()
{
	int N,Q;
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;i++){
		scanf("%lld",arr+i);
	}
	
	init(1,0,N-1);
	
	while(Q--)
	{
		u64 x,y,a,b;
		scanf("%lld %lld %lld %lld",&x,&y,&a,&b);
		
		if(x>y) swap(x,y);
		
		u64 diff = b - arr[a-1];
		arr[a-1] += diff;
		printf("%lld\n",sum(1,0,N-1,x-1,y-1));
		update(1,0,N-1,a-1,diff);
	}
	
	return 0;
}
