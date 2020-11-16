#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int,int>

vector<int> compr;

int getIdx(int x){
	return lower_bound(compr.begin(), compr.end(), x) - compr.begin();
}

int main()
{
	int N;
	scanf("%d",&N);
	
	vector<pair<pair<int, int>, int>> v;
	for(int i=0;i<N;i++){
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		
		compr.push_back(a);
		compr.push_back(b);
		v.push_back({{a,b},c});
	}
	
	sort(compr.begin(), compr.end());
	compr.erase(unique(compr.begin(), compr.end()), compr.end());
	//sort(v.begin(), v.end());
	for(int i=0;i<N;i++){
		v[i].first.first = getIdx(v[i].first.first);
		v[i].first.second = getIdx(v[i].first.second);
	}
	
	
	
	return 0;
}
