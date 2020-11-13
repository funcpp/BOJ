#include <stdio.h>
#include <memory.h>

using namespace std;
/*
1->3
2->1
3->3
4->7
5->3
6->4
7->6

1->3->3 순환X
2->1->3->3 순환X
3->3 순환O
4->7->6->4 순환O
5->3->3 순환X
6->4->7->6 순환O
7->6->4->7 순환O
*/

int line[100005];
int chk[100005];
int isAns[100005];

int cnt=0;

void dfs(int idx)
{	
	chk[idx]=1;
	if(chk[line[idx]])
	{
		if(!isAns[line[idx]])
		{
			for(int i=line[idx]; i!=idx; i=line[i])
			{
				cnt++;
			}
			cnt++;
		}
	}
	else
	{
		dfs(line[idx]);
	}
	isAns[idx]=true;
	
	return;
}

int main()
{
	int K;
	scanf("%d",&K);
	while(K--)
	{
		cnt=0;
		
		int n;
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			isAns[i]=0;
			chk[i]=0;
			scanf("%d",line+i);
		}
		
		for(int i=1; i<=n; i++)
		{
			if(!chk[i])
			{
				dfs(i);
			}
		}

		printf("%d\n",n-cnt);
	}
}
