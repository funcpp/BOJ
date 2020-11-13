#include <stdio.h>
int floyd[205][205];

int main()
{
	int N;
	scanf("%d",&N);
	int M;
	scanf("%d",&M);
	
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			scanf("%d",&floyd[i][j]);
			floyd[j][i] |= floyd[i][j];
		}
		floyd[i][i]=1;
	}
	
	for(int j=0; j<N; j++)
	{
		for(int i=0; i<N; i++)
		{
			for(int k=0; k<N; k++)
			{
				if(floyd[i][j] && floyd[j][k]) floyd[i][k]=1;
			}
		}
	}
	
	int p=-1;
	bool ans=true;
	for(int i=0; i<M; i++)
	{
		int t;
		scanf("%d",&t);
		t-=1;
		
		if(p!=-1)
		{
			if(!floyd[t][p] && !floyd[p][t])
			{
				ans=false;
			}
		}
		p=t;
	}
	
	printf("%s",ans?"YES":"NO");
	return 0;
}
