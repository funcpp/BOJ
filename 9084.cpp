#include <stdio.h>
#include <vector>
using namespace std;

vector<int> coin;
int ans;
int N,M;

int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		coin.clear();
		scanf("%d",&N);
		
		for(int i=0; i<N; i++)
		{
			int tmp;
			scanf("%d",&tmp);
			coin.push_back(tmp);
		}
		
		ans=0;
		scanf("%d",&M);
		f(0,M);
		
		printf("%d\n",ans);
	}
	return 0;
}
