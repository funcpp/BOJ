#include <stdio.h>

int N,M,K;

long long arr[1000001];
long long tree[1000001*4];
long long lazy[1000001*4];

long long init(int node, int l, int r)
{
	if(l == r) return tree[node] = arr[l];
	else
	{
		int mid = (l+r)/2;
		return tree[node] = init(node*2, l, mid) + init(node*2+1,mid+1,r);
	}
}

void update_lazy(int node, int nodeL, int nodeR)
{
	if( lazy[node])
	{
		tree[node] += (nodeR-nodeL+1) * lazy[node];
		if(nodeL != nodeR)
		{
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node]=0;
	}
	return;
}

long long update(int l, int r, long long value, int node=1, int nodeL=0, int nodeR=N-1)
{
	//printf("%d %d %d\n",node,nodeL,nodeR);
	update_lazy(node, nodeL, nodeR);
	
	if(r < nodeL || l > nodeR) return tree[node] ;
	
	if(l <= nodeL && nodeR <= r)
	{
		lazy[node] = value;
		update_lazy(node, nodeL, nodeR);
		return tree[node];
	}
	
	int mid = (nodeL + nodeR) / 2;
	return tree[node] = update(l,r, value, node*2, nodeL, mid) + update(l,r,value,node*2+1,mid+1,nodeR);
}

long long query(int l, int r, int node=1, int nodeL=0, int nodeR=N-1)
{
	update_lazy(node,nodeL,nodeR);
	
	if(r < nodeL || l > nodeR) return 0;
	if(l <= nodeL && nodeR <= r) return tree[node];
	
	int mid = (nodeL + nodeR) / 2;
	return query(l,r,node*2,nodeL,mid) + query(l,r,node*2+1,mid+1,nodeR);
}

int main()
{
	scanf("%d %d %d",&N,&M,&K);
	
	for(int i=0; i<N; i++)
	{
		scanf("%d",arr+i);
	}
	
	init(1,0,N-1);
	
	for(int i=0; i<M+K; i++)
	{
		int t;
		scanf("%d",&t);
		
		if(t==1)
		{
			long long a,b,c;
			scanf("%lld %lld %lld",&a,&b,&c);
			
			update(a-1,b-1,c);
		}
		else
		{
			long long a,b;
			scanf("%lld %lld",&a,&b);
			
			printf("%lld\n",query(a-1,b-1));
		}
	}
	
	return 0;
}
