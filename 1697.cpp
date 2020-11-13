#include <stdio.h>
#include <queue>
using namespace std;

struct info
{
	int pt, cnt;
};

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	queue<info> q;
	q.push({n,0});
	int chk[100005]={0,};
	
	while(!q.empty())
	{
		info cur = q.front();
		if(cur.pt==k)
		{
			break;
		}
		q.pop();
		
		chk[cur.pt]=1;
		
		if(cur.pt-1>=0 && !chk[cur.pt-1]) q.push({cur.pt-1,cur.cnt+1});
		if(cur.pt+1<=100000 && !chk[cur.pt+1]) q.push({cur.pt+1,cur.cnt+1});
		if(cur.pt*2<=100000 && !chk[cur.pt*2]) q.push({cur.pt*2,cur.cnt+1});
		
	}

	printf("%d",q.front().cnt);
	return 0;
}
