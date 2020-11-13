#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	
	int arr[N+1]={0,};
	for(int i=0; i<N; i++)
	{
		scanf("%d",arr+i);
	}
	
	int t[N+1]={0,};
	int ans=1;
	t[0] = arr[0];
	
	for(int i=1; i<N; i++)
	{
		if(t[ans-1] < arr[i])
		{
			t[ans]=arr[i];
			ans++;
			continue;
		}
		
		int idx = lower_bound(t,t+ans-1,arr[i]) -t;
		t[idx]=arr[i];
	}
	
	printf("%d",N-ans);
	
	return 0;
}
