#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int> > pq2;
	
	int N;
	scanf("%d",&N);
	
	for(int i=0;i<N;i++){
		int a;
		scanf("%d",&a);
		
		if(pq1.size()==pq2.size()) pq1.push(a);
		else pq2.push(a);
		
		if(pq1.size() && pq2.size() && pq2.top() < pq1.top())
		{
			int z=pq1.top(),x=pq2.top();
			swap(z,x);
			pq1.pop();pq1.push(z);
			pq2.pop();pq2.push(x);
		}
		printf("%d\n",pq1.top());
	}
	
	
	return 0;
}
