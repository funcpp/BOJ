#include <stdio.h>
#include <vector>

int N;
std::vector<int> line[100005];
int visit[100005];
int prt[100005];

void dfs(int idx)
{
	visit[idx]=1;
	for(int i=0; i<line[idx].size(); i++)
	{
		if(!visit[line[idx][i]])
		{
			prt[line[idx][i]]=idx;
			dfs(line[idx][i]);
		}
	}
}

int main()
{
	scanf("%d",&N);
	for(int i=0; i<N-1; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		line[a].push_back(b);
		line[b].push_back(a);
	}
	
	dfs(1);
	
	for(int i=2; i<=N; i++)
	{
		printf("%d\n",prt[i]);
	}
	
	return 0;
}
