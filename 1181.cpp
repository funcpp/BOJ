#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<string> v;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		v.push_back(s);
	}


	sort(v.begin(),v.end(), [](string a, string b) -> bool
	{
		if(a.size()==b.size())
			return a<b;
		else
			return a.size()<b.size();
	});
	
	v.erase(unique(v.begin(),v.end()),v.end());
	
	for(int i=0;i<v.size();i++){
		cout << v[i] << '\n';
	}
	return 0;
}
