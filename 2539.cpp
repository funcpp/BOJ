#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

#define pii pair<int, int> 

int N,M,K,P;
vector<pii> v;
vector<int> v_y;

bool chk(int s)
{
	int cur = -1;
	int cnt = 0;
	
	for(int i=0; i<v_y.size(); i++)
	{
		if(cur == -1)
		{
			cur = v_y[i];
			cnt++;
		}
		else
		{
			if(cur + s <= v_y[i])
			{
				cur = v_y[i];
				cnt++;
			}
		}
	}
	
	return cnt<=K;
}

int main()
{
	scanf("%d %d",&N,&M);
	scanf("%d",&K);
	scanf("%d",&P);

	int maxh=0;
	for(int i=0; i<P; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		
		v.push_back(pii(a,b));
		v_y.push_back(b);
		maxh=max(maxh,a);
	}
	sort(v.begin(), v.end());
	sort(v_y.begin(), v_y.end());
	
	int left=maxh, right = 1000000;
	int mid;
	
	while(left < right)
	{
		mid = (left + right) /2;
		
		if(chk(mid))
		{
			right = mid;
		}
		else
		{
			left = mid+1;
		}
	}
	
	printf("%d",left);
	
	return 0;
}
