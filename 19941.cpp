#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	
	string s;
	cin>>s;
	vector<int> ham;
	vector<int> per;
	
	for(int i=0;i<N;i++){
		if(s[i]=='H') ham.push_back(i);
		else per.push_back(i);
	}
	
	int hamptr=0, perptr=0;
	int ans=0;
	while(true){
		if(hamptr>=ham.size() || perptr>=per.size()) break;
		int d = abs(per[perptr]-ham[hamptr]);
		if(d<=K)
		{
			ans++;
			perptr++;
			hamptr++;
		}
		else
		{
			if(per[perptr]>ham[hamptr]) hamptr++;
			else perptr++;
		}
	}
	printf("%d",ans);
	
	return 0;
}
