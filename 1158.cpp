#include <stdio.h>
#include <queue>;

int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	
	std::queue<int> q;
	for(int i=1; i<=N; i++)
	{
		q.push(i);
	}
	
	printf("<");
	while(!q.empty())
	{
		for(int i=0; i<K-1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		printf("%d",q.front());
		if(q.size()>1) printf(", ");
		else printf(">");
		q.pop();
	}
	return 0;
}
