#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> m;
string ss[100005];
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main(){
	cin.tie(NULL);
	int N,M;
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++){
		string s;
		cin >> s;
		m[s]=i;
		ss[i]=s;
		
	}
	
	for(int i=0;i<M;i++){
		string s;
		cin >> s;
		
		if(m.count(s)) printf("%d\n",m[s]);
		else{
			int a = atoi(s.c_str());
			printf("%s\n",ss[a].c_str());
		}
	}
	return 0;
}
