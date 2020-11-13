#include <stdio.h>
#include <vector>
#include <utility>
#include <stdlib.h>

using namespace std;

vector<pair<int, int> > v;
vector<int> line[50000];

bool canMove(pair<int, int> p, pair<int, int> p2)
{
	return (abs(p.first-p2.first) <=2 && abs(p.second-p2.second) <=2);
}
	
int main()
{
	int n,T;
	scanf("%d %d",&n,&T);
	
	for(int i=0; i<n; i++)
	{
		int x, y;
		scanf("%d %d",&x,&y);
		
		for(int j=0; j<i-1; j++)
		{
			if(canMove({x,y},v[j]))
			{
				line[i].push_back(j);
			}
		}
		
		v.push_back({x,y});
	}
	
	
	
	return 0;
}
