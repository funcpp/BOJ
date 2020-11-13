#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

map<string, bool> b;
vector<string> v;
map<string, int> m;
map<string, int> m2;
	
int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=0; i<n; i++)
	{
		string name;
		cin >> name;
		
		if(!b[name])
		{
			//printf("input : %s\n",name.c_str());
			
			b[name]=true;
			v.push_back(name);
		}
		
		m[name]++;
	}
	
	for(int i=0; i<n-1; i++)
	{
		string name;
		cin >> name;
		
		//printf("_input : %s\n",name.c_str());
		m2[name]++;
	}
	
	
	int human = v.size();
	//printf("size %d\n",human);
	for(int i=0; i<human; i++)
	{
		//printf("%d : %s\n",i,v[i].c_str());
		if(m[v[i]]!=m2[v[i]])
		{
			printf("%s",v[i].c_str());
			//return 0;
		}
	}
	return 0;
}
