#include <stdio.h>
#include <deque>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	deque<char> l,r;
	string s;
	cin >>s;
	int len = s.length();
	for(int i=0; i<len; i++)
	{
		l.push_back(s.substr(i,1).c_str()[0]);
	}
	
	int n;
	scanf("%d",&n);
	
	for(int i=0; i<n; i++)
	{
		char c[2];
		scanf("%s",c);
		
		if(c[0]=='L' && !l.empty())
		{
			char b = l.back();
			l.pop_back();
			r.push_front(b);
		}
		else if(c[0]=='D' && !r.empty())
		{
			char f = r.front();
			r.pop_front();
			l.push_back(f);
		}
		else if(c[0]=='B' && !l.empty())
		{
			l.pop_back();
		}
		else if(c[0]=='P')
		{
			char cc[2];
			scanf("%s",cc);
			l.push_back(cc[0]);
		}
		
		/*
		printf("c : ");
		for(int i=0; i<l.size(); i++)
		{
			printf("%c",l[i]);
		}
		
		for(int i=0; i<r.size(); i++)
		{
			printf("%c",r[i]);
		}
		
		printf("\n");*/
	}
	
	for(int i=0; i<l.size(); i++)
	{
		printf("%c",l[i]);
	}
	
	for(int i=0; i<r.size(); i++)
	{
		printf("%c",r[i]);
	}
	
	return 0;
}
