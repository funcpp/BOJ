#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	int N,d,k,c;
	scanf("%d %d %d %d",&N,&d,&k,&c);
	
	int arr[N*2+1] = {0,};
	int eatCnt[d+1]={0,};
	int cur = 0;
	
	for(int i=0; i<N; i++)
	{
		int t;
		scanf("%d",&t);
		
		arr[i]=t;
		arr[i+N]=t;
	}
	
	
	if(!eatCnt[c]) cur++;
	eatCnt[c]++;
		
	for(int i=0; i<k-1; i++)
	{
		if(!eatCnt[arr[i]]) cur++;
		eatCnt[arr[i]]++;
	}
	
	int ans=0;
	
	for(int i=0; i<N; i++)
	{
		if(!eatCnt[arr[i+k-1]]) cur++;
		eatCnt[arr[i+k-1]]++;
		
		ans=ans<cur?cur:ans;
		
		eatCnt[arr[i]]--;
		if(!eatCnt[arr[i]]) cur--;
	}
	
	printf("%d",ans);
	
	return 0;
}
