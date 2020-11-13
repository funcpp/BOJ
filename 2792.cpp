#include <stdio.h>

int N,M;
int arr[300005];

int main()
{
	scanf("%d %d",&N,&M);
	int max=0;
	for(int i=0; i<M; i++)
	{
		scanf("%d",arr+i);
		max=max<arr[i]?arr[i]:max;
	}
	
	int left = 1, right = max;
	int mid;
	int minmid=987654321;
	while(left<right)
	{
		mid = (left+right)/2;
		
		int human=0;
		for(int i=0; i<M; i++)
		{
			human += arr[i]/mid;
			if(arr[i]%mid) human++;
		}
		
		bool isGood=(human<=N);
		
		if(isGood)
		{
			minmid = mid<minmid ? mid : minmid;
			right = mid;
		}
		else
		{
			left = mid+1;
		}
		
		//printf("%d %d %d\n",left,right,mid);
		
	}
	
	printf("%d",minmid);
	
	return 0;
}
