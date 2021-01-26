#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ml=0;
	vector<string> v;
	
	for(int i=0;i<5;i++){
		string s;
		cin>>s;
		v.push_back(s);
		ml=max(ml,(int)s.length());	
	}
	
	for(int i=0;i<ml;i++){
		for(int j=0;j<5;j++){
			if(v[j].size()>i) cout<<v[j][i];
		}
	}
}
