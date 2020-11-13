#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		vector<int> v[1005];
		int cnt[1005]={0,};
		map<int,int> chk[1005];
		
		int K,M,P;
		scanf("%d %d %d",&K,&M,&P);
		for(int i=1; i<=P; i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			v[a].push_back(b);
			cnt[b]++;
		}
		queue<int> q;
		int ans[1005]={0,};
		for(int i=1; i<=M; i++)
		{
			if(!cnt[i])
			{
				ans[i]=1;
				q.push(i);
			}
		}
		
		while(!q.empty())
		{
			int x = q.front(); q.pop();
			
			for(int i=0; i<v[x].size(); i++)
			{
				int nx = v[x][i];
				
				ans[nx]=max(ans[nx],ans[x]);
				chk[nx][ans[nx]]++;
				
				cnt[nx]--;
				
				if(!cnt[nx])
				{
					q.push(nx);
					
					if(chk[nx][ans[nx]] >=2) ans[nx]=ans[x]+1;
					else ans[nx]=ans[x];
				}
			}
		}
		
		printf("%d %d\n",K,ans[M]);
	}
	return 0;
}
