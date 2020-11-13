#include <stdio.h>
#include <memory.h>

int n;
int line[105][105];
int check[105];

void dfs(int idx)
{
	//check[idx]=1;
	for(int i=0; i<n; i++)
	{
		//if(i==idx) continue;
		if(!check[i] && line[idx][i])
		{
			check[i]=1;
			dfs(i);
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d",&line[i][j]);
		}
	}
	
	for(int i=0; i<n; i++)
	{
		dfs(i);
		
		for(int j=0; j<n; j++)
		{
			printf("%d ",check[j]);
		}
		printf("\n");
		memset(check,0,sizeof(check));
	}
}
