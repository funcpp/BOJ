#include <stdio.h>
#include <algorithm>
#include <vector>
#define fuck 987654321

using namespace std;

int N,M;
int S,D;
int line[10005][10005];
vector<int> ans;
int chk[10005];

void dfs(int idx, int goal, int dist)
{	
	if(idx==goal)
	{
		ans.push_back(dist);
		return;
	}
	
	for(int i=0; i<N; i++)
	{
		if(!chk[i] && line[idx][i]!=fuck)
		{
			chk[i]=1;
			dfs(i,goal,dist+line[idx][i]);
			chk[i]=0;
		}
	}
	
	return;

}
int main()
{
	while(true)
	{
		scanf("%d %d",&N,&M);
		if(N==0 && M==0) break;
		
		scanf("%d %d",&S,&D);
		
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				line[i][j]=fuck;
			}
		}
		
		for(int i=0; i<M; i++)
		{
			int U,V,P;
			scanf("%d %d %d",&U,&V,&P);
			
			line[U][V]=min(line[U][V],P);
		}
		
		dfs(S,D,0);
		
		sort(ans.begin(),ans.end());
		//printf("%d\n",ans[1]);
		for(int i=0; i<ans.size(); i++)
		{
			printf("ans : %d\n",ans[i]);
		}
		ans.clear();
	}
	
	return 0;
}
