
#include <bits/stdc++.h>
using namespace std;

int minE(vector<int> v)
{
	int ret = 10000000;
	
	for(int i=0; i<v.size(); i++)
	{
		if(v[i] < ret)
		{
			ret = v[i];
		}
	}
	return ret;
}
	
int main()
{
	int n, k;
	scanf("%d %d",&n,&k);
	vector<int> v;
	int sum[100005]={0,};
	
	for(int i=0; i<n; i++)
	{
		int t;
		scanf("%d",&t);
		v.push_back(t);
		sum[i]=t;
		if(i!=0) sum[i] += sum[i-1];
	}
	
	//sort(v.begin(),v.end());
	
	int ans=0;
	
	for(int i=0; i<k-1 i++) // i 시작점 
	{
		for(int j=1; j<k; j++) // j 끝점 
		{
			if()
		}
	}
	
	
	/*
	do
	{
		vector<int> m;
		for(int j=0; j<k; j++)
		{
			int t=0;
			for(int i=0; i<n/k; i++)
			{
				t+=v[i + j*(n/k)];
				//printf("%d ",i + j*(n/k));
			}
			m.push_back(t);
		}
		
		int me=  minE(m);
		if(ans < me)
		{
			ans = me;
		}
	}
	while(next_permutation(v.begin(),v.end()));*/
	
	/*vector<int> m;
	for(int j=0; j<k; j++)
	{
		int t=0;
		for(int i=0; i<n/k; i++)
		{
			t+=v[i + j*(n/k)];
		}
		m.push_back(t);
	}
	
	int me=  minE(m);
	ans=me;*/
	
	printf("%d",ans);
	
	
	return 0;
}
