#include <stdio.h>

int n,m;
int prt[1000005];

int find(int a)
{
	if(a==prt[a])
	{
		return a;
	}
	else
	{
		return prt[a] = find(prt[a]);
	}
}

void Union(int a, int b) //b를 a자식으로 
{
	a=find(a), b=find(b);
	if(a!=b) prt[b] = a;
}

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int i=0; i<=n; i++)
	{
		prt[i]=i;
	}
	
	for(int i=0; i<m; i++)
	{
		int m, a, b;
		scanf("%d %d %d",&m,&a,&b);
		
		if(m==0)
		{
			Union(a,b);
		}
		else
		{
			int ap = find(a), bp = find(b);
			if(ap==bp) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
