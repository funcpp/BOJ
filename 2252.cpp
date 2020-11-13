#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
	
int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	vector<int> graph[32005];
	queue<int> q;
	int cnt[32005]={0,}; //나한테 들어오는 선 수 
	for(int i=0; i<M; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
		cnt[b]++;
	}
	
	for(int i=1; i<=N; i++)
	{
		if(cnt[i]==0) q.push(i);
	}
	
	
	while(!q.empty())
	{
		int t = q.front();
		printf("%d ",t);
		q.pop();
		
		for(int i=0; i<graph[t].size(); i++)
		{
			cnt[graph[t][i]]--;
			if(cnt[graph[t][i]]==0) q.push(graph[t][i]);
		}
	}
	
	return 0;
}
