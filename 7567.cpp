#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int ans = 10;
	char prev = s[0];
	
	for(auto it = s.begin()+1;it!=s.end();it++){
		if(prev==*it){
			ans+=5;
		}else{
			prev=*it;
			ans+=10;
		}
	}
	printf("%d",ans);
	return 0;
}
