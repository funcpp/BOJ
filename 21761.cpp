#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	
	unsigned long long int len[4] = {0,};
	for(int i=0;i<4;i++){
		scanf("%llu",len+i);
	}
	
	vector<int> c[5];
	
	for(int i=0,U;i<N;i++){
		char t[3]={0,};
		scanf("%s %d",t,&U);
		c[t[0]-'A'].push_back(U);
	}
	
	for(int i=0;i<4;i++){
		sort(c[i].begin(), c[i].end(), [](int lhs, int rhs)->bool{return lhs>rhs;});
	}
	
	int used[4]={0,};
	for(int q=0;q<K;q++){
		vector<pair<unsigned long long int, int> > dx;
		for(int i=0;i<4;i++){
			dx.push_back({0,i});
			if(used[i]<c[i].size()){
				dx.back().first=c[i][used[i]];
			}
		}
		
		sort(dx.begin(), dx.end(), [&](auto  lhs, auto rhs)->bool{return len[rhs.second]*lhs.first > len[lhs.second]*rhs.first; });
		int idx = dx.front().second;
		len[idx]+=dx.front().first;
		printf("%c %d\n",idx+'A', dx.front().first);
		used[idx]++;
	}
		
	return 0;
}
