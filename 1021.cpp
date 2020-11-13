#include <stdio.h>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	
	deque<int> d;
	for(int i=1; i<=N; i++)
	{
		d.push_back(i);
	}
	
	vector<int> v;
	for(int i=0; i<M; i++)
	{
		int t;
		scanf("%d",&t);
		v.push_back(t);
	}
	
	int ans=0;
	for(int i=0; i<M; i++)
	{	
		if(d[0]==v[i])
		{
			d.pop_front();
		}
		else
		{
			int l=0,r=0;
			deque<int> t = d;
			deque<int> t2 = d;
			while(true)
			{
				t.push_back(t.front());
				t.pop_front();
				l++;
				
				if(t[0]==v[i]) break;
			}
			
			while(true)
			{
				t2.push_front(t2.back());	
				t2.pop_back();
				r++;
				
				if(t2[0]==v[i]) break;
			}
			
			if(l<r)
			{
				d=t;
				ans+=l;
			}
			else
			{
				d=t2;
				ans+=r;
			}
			
			d.pop_front();
		}
	}
	
	printf("%d",ans);
	
	return 0;
}
