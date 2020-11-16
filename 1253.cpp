#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	vector<int> v = vector<int>(N,0);
	for(int i=0;i<N;i++){
		scanf("%d",&v[i]);
	}
	sort(v.begin(), v.end());
	
	int ans = 0;
	for(auto it = v.begin(); it!=v.end();it++){
		bool b=false;
		for(auto it2 = v.begin(); it2!=v.end(); it2++){
			for(auto it3=lower_bound(v.begin(), v.end(), *it - *it2);it3!=v.end();it3++){
				if(*it3!=*it-*it2) break;
				if(it3!=it2 && it!=it2 && it!=it3){
					b=true;
					break;
				}
			}
			if(b) break;
		}
		if(b) ans++;
	}
	printf("%d",ans);
	return 0;
}
