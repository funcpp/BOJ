#include <stdio.h>
#include <memory.h>
#include <vector>

int n,m;
std::vector<int> line[10001];
int chk[10001];
int hCnt[10001];
int max=0;
void dfs(int idx, int cur)
{
	chk[cur]=1;
	hCnt[idx]++;
	if(max<hCnt[idx]) max=hCnt[idx];
	
	for(int i=0; i<line[cur].size(); i++)
	{
		if(!chk[line[cur][i]])
		{
			/*if(hCnt[line[cur][i]])
			{
				hCnt[idx]+=hCnt[line[cur][i]];
			}
			else */dfs(idx,line[cur][i]);
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		line[b-1].push_back(a-1);
	}
	
	for(int i=0; i<n; i++)
	{
		memset(chk,0,sizeof(chk));
		dfs(i,i);
	}

	for(int i=0; i<n; i++)
	{
		if(hCnt[i]==max)
		{
			printf("%d ",i+1);
		}
	}
	
	return 0;
}
