#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

class Node
{
public:
	int a=0,b=0;
	
	Node()
	{
		a=0;
		b=0;
	}
	
	Node(int A, int B)
	{
		a=A;
		b=B;
	}
	
	int& getLow()
	{
		if(a<b) return a;
		else return b;
	}
	
	int& getHigh()
	{
		if(a>b) return a;
		else return b;
	}
	
	int getSum()
	{
		return a+b;
	}
	
	void update(Node x, Node y)
	{
		int c[6] ={this->a, this->b, x.a, x.b, y.a, y.b};
		sort(c,c+6);
		
		this->a = c[5];
		this->b = c[4];
	}
	
	void update(int value)
	{
		if(this->getLow() < value)
		{
			this->getLow() = value;
		}
	}
};

int N,M;
int A[100005];
vector<Node> tree;

Node init(int idx, int l, int r)
{
	if(l==r)
	{
		tree[idx].update(A[l]);
	}
	else
	{
		int mid = (l+r)/2;
		tree[idx].update(init(idx*2, l, mid),init(idx*2+1,mid+1,r));
	}
	
	return tree[idx];
}

Node update(int idx, int l, int r, int node, int value)
{
	if(node < l || r < node) return Node();
	if(node<=l && r<=node)
	{
		tree[idx].update(value);
		return tree[idx];
	}
	
	int mid = (l+r)/2;
	Node q1 = update(idx*2,l,mid,node,value);
	Node q2 = update(idx*2+1,mid+1,r,node,value);
	
	tree[idx].update(q1,q2);
	
	return tree[idx];
}

Node query(int idx, int l, int r, int node_l, int node_r)
{
	if(node_r < l || r < node_l) return Node();
	if(node_l <= l && r <= node_r) return tree[idx];
	
	int mid = (l+r)/2;
	Node q1 = query(idx*2, l, mid, node_l, node_r);
	Node q2 = query(idx*2+1, mid+1, r, node_l, node_r);
	
	Node ret;
	ret.update(q1,q2);
	return ret;
}

int main()
{
	scanf("%d",&N);
	tree=vector<Node>(N*4,Node());
	for(int i=0; i<N; i++)
	{
		scanf("%d",A+i);
	}
	
	init(1,0,N);
	
	scanf("%d",&M);
	
	while(M--)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		b--;
		if(a==1)
		{
			update(1,0,N,b,c);
		}
		else
		{
			c--;
			printf("%lld\n",query(1,0,N,b,c).getSum());
		}
	}
	
	return 0;
}
