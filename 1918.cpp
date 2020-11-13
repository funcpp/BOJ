#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	cin >> s;
	
	int len = s.length();
	
	string ans = "";
	vector<char> v;
	
	for(int i=0; i<len; i++)
	{
		if('A' <= s[i] && s[i] <= 'Z')
		{
			ans += s[i];
		}
		else
		{
			if(s[i]=='(')
			{
				v.push_back(s[i]);
			}
			else if(s[i]=='*' || s[i] =='/')
			{
				if(v.size())
				{
					while(v.size() && (v.back()=='*' || v.back() =='/' ))
					{
						ans += v.back();
						v.pop_back();
					}
				}
				v.push_back(s[i]);
			}
			else if(s[i]=='+' || s[i]=='-')
			{
				if(v.size())
				{
					while(v.size() && (v.back()=='*' || v.back() =='/' || v.back()=='+' || v.back() =='-' || v.back()==')'))
					{
						ans += v.back();
						v.pop_back();
					}
				}
				v.push_back(s[i]);
			}
			else // )
			{
				if(v.size())
				{
					while(v.size() && v.back() != '(')
					{
						ans += v.back();
						v.pop_back();
					}
				}
				v.pop_back();
			}
		}
	}
	
	for(int i=v.size()-1; i>=0; i--)
	{
		ans+=v[i];
	}
	printf("%s",ans.c_str());
	
	return 0;
}
