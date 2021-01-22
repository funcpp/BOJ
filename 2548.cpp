#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	int arr[N+5]={0,};
	for(int i=0;i<N;i++){
		scanf("%d",arr+i);
	}
	sort(arr,arr+N);
	printf("%d",arr[N%2?N/2:(N/2-1)]);	
	return 0;
}
