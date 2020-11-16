#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	int N,M,K;
	scanf("%d %d",&N,&M);
	
	vector<string> sv;
	
	for(int i=0; i<N; i++)
	{
		char c[1024];
		scanf("%s",c);
		sv.push_back(c);
	}
	scanf("%d",&K);
	
	unordered_map<string, int> m;
	int ans=0;
	for(int i=0; i<N; i++)
	{
		int zero_cnt = 0;
		for(int j=0; j<M; j++)
		{
			if(sv[i][j]=='0') zero_cnt++;
		}
		
		if(zero_cnt <= K && (K-zero_cnt)%2 == 1)
		{
			m[sv[i]]++;
			ans = max(ans, m[sv[i]]);
		}
	}
	printf("%d",ans);
	
}
