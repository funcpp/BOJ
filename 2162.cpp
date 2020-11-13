#include <stdio.h>
#include <vector>
using namespace std;

struct line
{
	float x1,y1,x2,y2;	
};

vector<line> ls;

int prt[3005];
int size[3005];

int find(int a)
{
	if(a==prt[a])
		return a;
	
	return prt[a]=find(a);
}

void merge(int a, int b)
{
	a=find(a);
	b=find(b);
	
	if(a==b) return;
	
	if(size[a]>size[b])
	{
		prt[b]=a;
		size[a]+=size[b];
	}
	else
	{
		prt[a]=b;
		size[b]+=size[a];	
	}
	
	return;
}

int main()
{
	int N;
	scanf("%d",&N);
	
	for(int i=0; i<=N; i++)
	{
		prt[i]=i;
		size[i]=1;
	}
	
	for(int i=0; i<N; i++)
	{
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		line.push_back({x1,y1,x2,y2});	
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			float a = (y2-y1)/(x2-x1);
		}
	}
	
	
	return 0;
}
