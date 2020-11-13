#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	queue<int> q;
	
	while(n--)
	{
		char cmd[10];
		scanf("%s",cmd);
		
		if(!strcmp(cmd,"push"))
		{
			int t;
			scanf("%d\n",&t);
			q.push(t);
		}
		else if(!strcmp(cmd,"pop"))
		{
			printf("%d\n",q.empty()?-1:q.front());
			if(!q.empty()) q.pop();
		}
		else if(!strcmp(cmd,"size"))
		{
			printf("%d\n",q.size());
		}
		else if(!strcmp(cmd,"empty"))
		{
			printf("%d\n",q.empty()?1:0);
		}
		else if(!strcmp(cmd,"front"))
		{
			printf("%d\n",q.empty()?-1:q.front());
		}
		else if(!strcmp(cmd,"back"))
		{
			printf("%d\n",q.empty()?-1:q.back());
		}
	}
	return 0;
}
