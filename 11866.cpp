#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	queue<int> q;
	
	for(int i=1; i<=n; i++)
		q.push(i);
	
	printf("<");
	while(!q.empty())
	{
		for(int i=0; i<k-1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		printf("%d",q.front());
		q.pop();
		if(q.size()) printf(", ");
	}
	
	printf(">");
	
	return 0;
}
