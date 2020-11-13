#include <stdio.h>
int h[100005];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		scanf("%d",h+i);
	}
	int max=0;
	int ans=0;
	for(int i=N-1; i>=0; i--)
	{
		if(h[i] > max)
		{
			ans++;
		}
		if(max < h[i]) max = h[i];
	}
	
	printf("%d",ans);
	
	return 0;
}
