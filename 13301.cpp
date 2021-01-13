#include<bits/stdc++.h>
using namespace std;
#define uint64_t long long int
int main()
{
	uint64_t N;
	scanf("%lld",&N);
	
	uint64_t size[2]={1,1}; //w, h
	int idx = 1;
	uint64_t d[100]={0,}, *arr = d+1;
	arr[-1]=0;
	arr[0]=1;

	for(int i=1;i<N;i++)
	{
		arr[i] = arr[i-1]+arr[i-2];
		size[idx]+=arr[i];
		idx^=1;
	}
	
	printf("%lld",size[0]*2+size[1]*2);
	
	return 0;
}
