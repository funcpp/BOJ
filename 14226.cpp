#include <stdio.h>
#include <queue>
using namespace std;

struct st
{
	int n,c,t;
};

int chk[1005][1005];
	
int main()
{
	int S;
	scanf("%d",&S);
	
	queue<st> q;
	q.push({1,0,0});
	
	//int ans[1005]={0,};
	
	while(!q.empty())
	{
		st s = q.front();
		q.pop();
		
		if(s.n==S)
		{
			printf("%d",s.t);
			break;
		}
		
		if(s.n && s.n<=1000 && !chk[s.n][s.n])
		{
			chk[s.n][s.n]=true;
			q.push({s.n,s.n,s.t+1});
		}
		
		if(s.n && s.n<=1000 && !chk[s.n-1][s.c])
		{
			chk[s.n-1][s.c]=true;
			q.push({s.n-1,s.c,s.t+1});
		}
		
		if(s.c && s.c+s.n <=1000 && !chk[s.n+s.c][s.c])
		{
			chk[s.n+s.c][s.c]=true;
			q.push({s.n+s.c,s.c,s.t+1});
		}
	}
	
	return 0;
}
