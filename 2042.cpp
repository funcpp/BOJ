#include <stdio.h>
#define MAX 1000000
long long a[MAX+5];
long long tree[MAX*4];

void update(int idx, int node_start, int node_end, int queryIdx, int value)
{
	if(node_end < queryIdx || queryIdx < node_start) return;

	if(node_start != node_end)
	{
		long long mid = (node_start + node_end)/2;
		
		update(idx*2, node_start, mid, queryIdx, value);
		update(idx*2+1, mid+1, node_end, queryIdx, value);
		
		tree[idx] = tree[idx*2] + tree[idx*2+1];
	}
	else tree[idx]=value;
}

long long sum(int idx, int node_start, int node_end, int query_start, int query_end)
{
	if(node_end < query_start || query_end < node_start) return 0;
	if(query_start <= node_start && node_end <= query_end) return tree[idx];
	
	long long mid = (node_start + node_end)/2;
	
	return sum(idx*2,node_start,mid,query_start,query_end) + sum(idx*2+1,mid+1,node_end,query_start,query_end);
}

int main()
{
	int N,M,K;
	scanf("%d %d %d",&N,&M,&K);
	
	for(int i=0; i<N; i++)
	{
		scanf("%d",a+i);
		
		update(1,1,N,i+1,a[i]);
	}
	
	for(int i=0; i<M+K; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		
		if(a==1)
		{
			update(1,1,N,b,c);
		}
		else
		{
			printf("%lld\n",sum(1,1,N,b,c));
		}
	}
	
	return 0;
}
