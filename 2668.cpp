#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>

int N;
int node[105];
int chk[105];
std::vector<int> ans;
int cnt=0;
int ansChk[105];

void dfs(int idx, int i)
{
	chk[i]++;
	
	if(chk[node[i]]==0 || chk[node[i]]==1)
	{
		dfs(idx,node[i]);
	}
	else if(chk[node[i]]==2 && !ansChk[node[i]])
	{
		ansChk[node[i]]=1;
		ans.push_back(node[i]);
		cnt++;
	}
	
	return;
}
int main()
{
	scanf("%d",&N);
	for(int i=1; i<=N; i++)
	{
		scanf("%d",node+i);
	}
	
	for(int i=1; i<=N; i++)
	{
		dfs(i,i);
		memset(chk,0,sizeof(chk));
	}
	
	std::sort(ans.begin(),ans.end());
	printf("%d\n",cnt);
	for(int i=0; i<cnt; i++)
	{
		printf("%d\n",ans[i]);
	}
	
	return 0;
}
