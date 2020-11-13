#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
int N,M,K;
vector<vector<int> > v;
vector<int> ind, chk;
int main()
{
	scanf("%d %d %d",&N,&M,&K);
	v=vector<vector<int> >(N+1,vector<int>());
	ind=vector<int>(N+1,0);
	chk=ind;
	map<pair<int,int>, bool> m;
	
	for(int i=0; i<M; i++)
	{
		int from,to;
		scanf("%d %d",&from,&to);
		
		v[from].push_back(to);
		ind[to]++;
	}
	
	bool lier=false;
	for(int i=0; i<K; i++)
	{
		int q, a;
		scanf("%d %d",&q,&a);
		
		if(q==1) //건설 
		{
			if(ind[a]==0)
			{
				chk[a]++;
				for(auto x : v[a])
				{
					if(m[{x,a}]==false)
					{
						m[{x,a}]=true;
						ind[x]--;
					}
				}
			}
			else
			{
				lier=true;
			}
		}
		else //파괴 
		{
			if(chk[a]==0) //건설 x 
			{
				lier=true;
			}
			else
			{
				chk[a]--;
				if(chk[a]==0)
				{
					for(auto x : v[a])
					{
						m[{x,a}]=false;
						ind[x]++;
					}
				}
			}
		}
	}
	puts(lier?"Lier!":"King-God-Emperor");
	return 0;
}
