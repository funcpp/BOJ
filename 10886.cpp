#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int cnt[2]{};
	while(N--)
	{
		int t;
		scanf("%d",&t);
		cnt[t]++;
	}
	
	printf("%s",(cnt[0] > cnt[1]) ? "Junhee is not cute!" : "Junhee is cute!");
	
	return 0;
}
