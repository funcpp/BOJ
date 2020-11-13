#include <stdio.h>
#include <queue>
using namespace std;

int N;
int time[10005];
vector<int> v[10005];
int cnt[10005];
int ans[10005];

int main()
{
	scanf("%d",&N);
	
	queue<int> q;
	
	for(int i=1; i<=N; i++)
	{
		scanf("%d %d",time+i,cnt+i);
		for(int j=0; j<cnt[i]; j++)
		{
			int b;
			scanf("%d",&b);
			v[b].push_back(i);
		}
		if(!cnt[i])
		{
			q.push(i);
			ans[i]=time[i];
		}
	}
	
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i=0; i<v[x].size(); i++)
		{
			int nx = v[x][i];
			cnt[nx]--;
			
			if(!cnt[nx]) q.push(nx);
			ans[nx]=ans[nx]<ans[x]+time[nx]?ans[x]+time[nx]:ans[nx];
		}
	}
	
	int _ans=0;
	for(int i=1; i<=N; i++) _ans=max(_ans,ans[i]);
	printf("%d",_ans);
	return 0;
}
