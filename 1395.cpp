#include <stdio.h>

int N,M,K;

long long arr[1000001];
long long tree[1000001*4];
long long lazy[1000001*4];

void update_lazy(int node, int nodeL, int nodeR)
{
	if( lazy[node])
	{
		tree[node] = lazy[node];
		if(nodeL != nodeR)
		{
			lazy[node*2] = lazy[node];
			lazy[node*2+1] = lazy[node];
		}
		lazy[node]=0;
	}
	return;
}

long long update(int l, int r, int node=1, int nodeL=0, int nodeR=N-1)
{
	//printf("%d %d %d\n",node,nodeL,nodeR);
	update_lazy(node, nodeL, nodeR);
	
	if(r < nodeL || l > nodeR) return tree[node] ;
	
	if(l <= nodeL && nodeR <= r)
	{
		lazy[node] = (nodeR - nodeL +1 - lazy[node]);
		update_lazy(node, nodeL, nodeR);
		return tree[node];
	}
	
	int mid = (nodeL + nodeR) / 2;
	return tree[node] = update(l,r, node*2, nodeL, mid) + update(l,r,node*2+1,mid+1,nodeR);
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
	scanf("%d %d",&N,&M);
	
	for(int i=0; i<M; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		
		if(!a)
		{
			update(b-1,c-1);
		}
		else
		{
			printf("%lld\n",query(b-1,c-1));
		}
	}
	
	return 0;
}
