#include <stdio.h>
#include <memory.h>

int n,k,s;
int line[405][405];

int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0; i<k; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b); 
		line[a][b]=-1; //앞->뒤 
		line[b][a]=1; //뒤->앞 
	}
	
	for(int j=1; j<=n; j++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int k=1; k<=n; k++)
			{
				if(line[i][k]==0)
				{
					if(line[i][j]==1 && line[j][k]==1) line[i][k]=1;
					else if(line[i][j]==-1 && line[j][k]==-1) line[i][k]=-1;
				}
			}
		}
	}
	
	scanf("%d",&s);
	for(int i=0; i<s; i++)
	{
		int a,b;
		scanf("%d %d",&a, &b);
		printf("%d\n",line[a][b]);
	}
	
	return 0;
}
