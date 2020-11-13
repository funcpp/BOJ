#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int N;
vector<int> v;

int main()
{
	scanf("%d",&N);
	
	for(int i=0; i<N; i++)
	{
		int a;
		scanf("%d",&a);
		
		v.push_back(a);
	}
	
	int cnt = 0;
	unordered_map<int,bool> m;
	for(int i=0; i<N; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			if(!m.count(v[i]+v[j]))
			{
				m[v[i]+v[j]]=true;
				auto it = lower_bound(v.begin(), v.end(), v[i]+v[j]);
				auto it2 = upper_bound(v.begin(), v.end(), v[i]+v[j]);
				cnt+=(it2-it);
			}
		}
	}
	printf("%d",cnt);
	
	return 0;
}
