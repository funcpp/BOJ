#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,K;
		scanf("%d %d",&N,&K);
		int time[1005]={0,};
		for(int i=1; i<=N; i++)
		{
			scanf("%d",time+i);
		}
		
		vector<int> graph[1005];
		queue<int> q;
		int cnt[1005]={0,};
		for(int i=0; i<K; i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			graph[x].push_back(y);
			cnt[y]++;
		}
		
		int w;
		scanf("%d",&w);
		
		int ans[1005]={0,};
		for(int i=1; i<=N; i++)
		{
			if(!cnt[i])
			{
				q.push(i);
				ans[i]=time[i];
			}
		}
		
		while(!q.empty())
		{
			int t = q.front();
			q.pop();
			if(t==w) break;
			
			for(int i=0; i<graph[t].size(); i++)
			{
				int tt = graph[t][i];
				cnt[tt]--;
				if(!cnt[tt]) q.push(tt);
				ans[tt] = ans[tt]<ans[t]+time[tt] ? ans[t]+time[tt] : ans[tt];
			}
		}
		printf("%d\n",ans[w]);
	}
	return 0;
}
