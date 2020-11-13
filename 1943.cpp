#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

vector<int> coin;
map<int> coinMap;
vector<pair<int,int> > coins;

int main()
{
	int T=3;
	while(T--)
	{
		coin.clear();
		
		int c;
		scanf("%d",&c);
		int total=0;
		
		for(int i=0; i<c; i++)
		{
			int money, cnt;
			scanf("%d %d",&money,&cnt);
			coins.push_back({money,cnt});
			total+=money*cnt;
			while(cnt--) coin.push_back(money);
		}
		
		if(total%2==1)
		{
			printf("0\n");
			continue;
		}
		
		int chalf = coin.size()/2;
		int half = total/2;
		
		/*
		sort(coins.begin(),coins.end(),[](pair<int, int> p, pair<int, int> p1)
		{
			return p.money > p1.money;	
		});
		
		coins[0].second %=2;*/
		
		int dp[100005]={0,};
		
		
	}
}
