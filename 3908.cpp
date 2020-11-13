#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> pn;
int dp[1125][15];
int parr[1121];
 	
map<pair<pair<int, int>, int>, bool> m;
 	
int main()
{	
	for(int i=2; i<=1120; i++)
	{
		if(!parr[i])
		{
			pn.push_back(i);
			//dp[i][1]=1;
			
			for(int j=i*2; j<=1120; j+=i)
			{
				parr[j]=1;
			}
		}	
	}
	
	dp[0][0]=1;
	for(int i=0; i<pn.size(); i++)
	{
		for(int j=1120; j>=pn[i]; j--)
		{
			for(int k=1; k<=14; k++)
			{
				//if(!m.count({{j,k},pn[i]}))
				//{
					dp[j][k]+=dp[j-pn[i]][k-1];
					//m[{{j,k},pn[i]}]=true;
				//}
			}
		}
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		
		if(n==1)
		{
			printf("0\n");
			continue;	
		}
		
		printf("%d\n",dp[n][k]);
	}
	return 0;
}
