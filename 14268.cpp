#include <stdio.h>
#include <vector>
#include <utility>
#include <map>
using namespace std;

vector<int> graph[100001];
int arr[100001];
int 
map<int, pair<int,int> > idx;

int cnt=0;
void dfs(int x)
{
	idx[x].first = cnt++;
	
	for(auto nx : graph[x])
	{
		dfs(nx);
	}
	
	idx[x].second = cnt++;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++)
	{
		int t;
		scanf("%d",&t);
		if(t!=-1)
		{
			graph[t-1].push_back(i);
		}
	}
	
	for(int i=0; i<m; i++)
	{
		int t;
		scanf("%d",&t);
		
		if(t==1)
		{
			int ii,w;
			scanf("%d %d",&ii,&w);
		}
	}
	
	return 0;
}
