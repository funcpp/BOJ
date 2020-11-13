#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int L,C;
vector<char> v;

bool isValid(string s)
{
	int m=0,j=0;
	int len = s.length();
	for(int i=0; i<len; i++)
	{
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' ||s[i]=='u')
		{
			m++;
		}
		else
		{
			j++;
		}
		
		if(m>=1 && j>=2)
		{
			return true;
		}
	}
	
	return false;
}

void bf(int cnt, string s, int c)
{
	if(c>C) return;
	
	if(cnt==L)
	{
		if(isValid(s)) cout << s << endl;
		return;
	}
	
	bf(cnt+1,s+string(1,v[c]),c+1);
	bf(cnt,s,c+1);
	
	return;
}

int main()
{
	scanf("%d %d",&L,&C);

	for(int i=0; i<C; i++)
	{
		string s;
		cin >> s;
		v.push_back(s.substr(0,1).c_str()[0]);
	}
	
	std::sort(v.begin(),v.end());
	
	bf(0,"",0);
	
	return 0;
}
