#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

void rm(vector<string>& v)
{
	int size = v.size();
	
	for(int i=0; i<size; i++)
	{
		v[i] = v[i].substr(1,v[i].length()-1);
	}
}

bool stop(vector<string> v)
{
	map<string, bool> m;
	
	bool d = false;
	int size = v.size();
	for(int i=0; i<size; i++)
	{
		if(m[v[i]])
		{
			d=true;
			break;
		}
		else
		{
			m[v[i]]=true;
		}
	}
	
	return d;
}

int main()
{
	int R,C;
	scanf("%d %d",&R,&C);
	
	vector<string> v;
	
	for(int i=0; i<R; i++)
	{
		string s;
		cin >> s;
		
		v.push_back(s);
	}
	
	vector<string> vs;
	
	for(int i=0; i<C; i++)
	{
		string s="";
		for(int j=0; j<R; j++)
		{
			s+=v[j][i];
		}
		vs.push_back(s);
	}
	
	int ans=0;
	
	/*
	for(int i=0; i<R; i++)
	{
		rm(vs);
		
		if(!stop(vs)) ans++;
		else break;
	}*/
	
	
	
	printf("%d",ans);
	
	return 0;	
}
