#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
#define pii pair<int, int>
#define piii pair<pii, int>

int N;
vector<piii> coords;
vector<piii> compr;


class ANode
{
public:
	left,right,sum,middle;
	
	
}

vector<long long> tree;

int getComprIdx(piii p)
{
	return lower_bound(compr.begin(), compr.end(), p) - compr.begin();
}

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

long long query(int idx, int node_start, int node_end, int query_start, int query_end)
{
	if(node_end < query_start || query_end < node_start) return 0;
	if(query_start <= node_start && node_end <= query_end) return tree[idx];
	
	long long mid = (node_start + node_end)/2;
	
	return query(idx*2,node_start,mid,query_start,query_end) + query(idx*2+1,mid+1,node_end,query_start,query_end);
}

int main()
{
	scanf("%d",&N);
	
	coords = vector<piii>(N,piii());
	tree = vector<long long(N*4,0);
	
	for(int i=0; i<N; i++)
	{
		scanf("%d %d %d",&coords[i].first.first, &coords[i].first.second, &coords[i].second);
		compr.push_back(coords.back());
	}
	
	sort(compr.begin(), compr.end());
	compr.erase(unique(compr.begin(), compr.end()), compr.end());
	
	for(int i=0; i<N; i++)
	{
		for(int j=i; j<N; j++)
		{
			update(1,0,N, )
		}
		
		tree.clear();	
	}
	
	return 0;
}
