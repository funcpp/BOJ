#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int cache[3][2], cache2[3], cache3[3][2];

int main()
{
	int N;
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<3;j++)scanf("%d",&cache2[j]);
		
		if(i==0)for(int j=0;j<3;j++)for(int k=0;k<2;k++)cache[j][k]=cache2[j];
		else
		{
			for(int k=0;k<2;k++)
			{
				cache3[0][k] = max(cache[0][k], cache[1][k]) + cache2[0];
				cache3[1][k] = max(max(cache[0][k], cache[1][k]), cache[2][k]) + cache2[1];
				cache3[2][k] = max(cache[1][k], cache[2][k]) + cache2[2];
			}
			
			for(int j=0;j<3;j++){for(int k=0;k<2;k++){cache[j][k]=cache3[j][k];}}
		}
		
	}
	
	printf("%d %d", max({cache[0][0],cache[1][0],cache[2][0]}), min({cache[0][1],cache[1][1],cache[2][1]}));
	return 0;
}
