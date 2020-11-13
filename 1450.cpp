#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

long long ans;
long long N,C;
long long arr[35];
long long half;

map<long long,long long> mL,mR;
vector<long long> L,R;

void bfL(int idx, int c)
{
	if(c>C) return;
	
	if(idx>=half)
	{
		L.push_back(c);
		mL[c]++;
		return;
	}
	
	bfL(idx+1,c);
	bfL(idx+1,c+arr[idx]);
}

void bfR(int idx, int c)
{
	if(c>C) return;
	
	if(idx>=N)
	{
		R.push_back(c);
		mR[c]++;
		return;
	}
	
	bfR(idx+1,c);
	bfR(idx+1,c+arr[idx]);
}

int main()
{
	scanf("%d %d",&N,&C);
	half = N / 2;
	for(int i=0; i<N; i++)
	{
		scanf("%d",arr+i);
	}
	
	bfL(0,0);
	bfR(half,0);
	
	sort(L.begin(),L.end());
	sort(R.begin(),R.end());
	
	int t = R.size()-1;
	for(int i : L)
	{
		while(t && i + R[t] > c) t--;
		ans += e+1;
	}
	
	printf("%lld",ans);
	
	return 0;
}
