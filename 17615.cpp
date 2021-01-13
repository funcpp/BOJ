#include<bits/stdc++.h>
using namespace std;
int main()
{
	int bbr=0, brb=0, rbr=0, rrb=0;
	int N;
	scanf("%d",&N);
	string s;
	cin>>s;
	
	deque<int> r,b;
	for(int i=0;i<N;i++){
		if(s[i]=='R')r.push_back(i);
		else b.push_back(i);
	}
	
	int t=0;
	for(t=0;s[t]=='B';t++);
	bbr = b.size()-t;
	for(t=N-1;s[t]=='B';t--);
	brb = b.size()-(N-1-t);
	for(t=0;s[t]=='R';t++);
	rrb = r.size()-t;
	for(t=N-1;s[t]=='R';t--);
	rbr = r.size()-(N-1-t);
	
	printf("%d",min(bbr,min(brb,min(rbr,rrb))));
	
	return 0;
}
