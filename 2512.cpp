#include<bits/stdc++.h>
using namespace std;

int N,M, A[10005]={0,},high=0;

bool can(int l)
{
	long long int sum=0;
	for(int i=0;i<N;i++){
		sum += min(A[i],l);
	}
	return sum<=M;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",A+i);
		high=max(high,A[i]);
	}
	scanf("%d",&M);
	
	int left = 0, right = high, res=0;
	while(left <= right)
	{
		int mid = (left+right)/2;
		
		if(can(mid)){ //»óÇÑ¼± ²ø¿Ã
			res=mid;
			left=mid+1;
		}
		else
			right = mid-1;
	}
	
	printf("%d",res);
	
	
	return 0;
}
