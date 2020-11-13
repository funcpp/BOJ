#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

int N,S;
int half;
int arr[41];
long long ans;
//vector<pair<int, int> > L,R;
unordered_map<int, int> mL;

void dfsL(int idx, int s, int c)
{
	if(idx==half)
	{
		mL[s]++;
		return;
	}

	dfsL(idx+1,s,c);
	dfsL(idx+1,s+arr[idx],c+1);
	
	return;
}

void dfsR(int idx, int s, int c)
{
	if(idx==N)
	{
		ans+=mL[S-s]; 
		return;
	}
	
	dfsR(idx+1,s,c);
	dfsR(idx+1,s+arr[idx],c+1);
	
	return;
}

int main()
{
	scanf("%d %d",&N,&S);
	
	half = N/2;
	
	for(int i=0; i<N; i++)
	{
		scanf("%d",arr+i);
	}
	
	dfsL(0,0,0);
	dfsR(half,0,0);

	/*
	int sizeL = L.size();
	int sizeR = R.size();
	
	for(int i=0; i<sizeL; i++)
	{
		for(int j=0; j<sizeR; j++)
		{
			if(L[i].second+R[j].second && L[i].first+R[j].first==S)
			{
				ans++;
			}
		}
	}*/
	
	printf("%lld",(S==0?ans-1:ans));
	
	return 0;
}
