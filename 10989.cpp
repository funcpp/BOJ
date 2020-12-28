#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	int arr[10005]={0,};
	while(N--){
		int a;
		scanf("%d",&a);
		arr[a]++;
		//v.push_back(a);
	}
	for(int i=0;i<=10000;i++){
		for(int j=0;j<arr[i];j++){
			printf("%d\n",i);
		}
	}
}
