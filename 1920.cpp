#include <stdio.h>
#include <algorithm>

int main()
{
	int N;
	scanf("%d",&N);
	int A[N+1]={0,};
	for(int i=0; i<N; i++)
	{
		scanf("%d",A+i);
	}
	std::sort(A,A+N);
	int M;
	scanf("%d",&M);
	
	while(M--)
	{
		int key;
		scanf("%d",&key);
		int left=0;
		int right=N-1;
		bool found=false;
		if(A[left]==key || A[right]==key) found=true;
		while(left <= right && !found)
		{
			int mid=(left+right)/2;
			if(A[mid] < key) left=mid+1;
			else if(key < A[mid]) right=mid-1;
			else if(key==A[mid]) found=true;
		}
		printf("%d\n",found?1:0);
	}
	return 0;
}
