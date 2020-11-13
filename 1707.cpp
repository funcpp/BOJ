#include <stdio.h>
#include <memory.h>
#include <vector>

int V,E;
int map[20005];
std::vector<int> line[20005];

void dfs(int idx, int num)
{
	map[idx]=num;
	
	for(int j=0; j<line[idx].size(); j++)
	{
		if(!map[line[idx][j]])
		{
			dfs(line[idx][j],num^3);
		}
	}
	
	return;
}

int main()
{
	int K;
	scanf("%d",&K);
	
	while(K--)
	{
		scanf("%d %d",&V,&E);
		
		for(int i=0; i<E; i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			line[a-1].push_back(b-1);
			line[b-1].push_back(a-1);
		}
		
		for(int i=0; i<V; i++)
		{
			if(!map[i])
			{
				dfs(i,1);
			}
		}
		
		bool b=true;
		for(int i=0; i<V; i++)
		{
			for(int j=0; j<line[i].size(); j++)
			{
				if(i==j) continue;
				
				if(map[line[i][j]]==map[i])
				{
					b=false;
					break;
				}	
			}
			if(!b) break;
		}
		printf("%s",b ? "YES\n" : "NO\n");
		
		memset(map,0,sizeof(map));
		memset(line,0,sizeof(line));
	}
}
