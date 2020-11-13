#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
	string cipher="";
	cin >> cipher;
	int n;
	scanf("%d",&n); 
	
	//vector<char*> types;
	vector<int> len;
	for(int i=0; i<n; i++)
	{
		char str[12]={};
		scanf("%s",str);
		//types.push_back(str);
		if(strcmp(str,"char")==0) len.push_back(2);
		else if(strcmp(str,"int")==0) len.push_back(8);
		else if(strcmp(str,"long_long")==0) len.push_back(16);
	}
	
	int cIdx=0;
	vector<string> value;
	
	for(int i=0; i<n; i++)
	{
		value.push_back(cipher.substr(cIdx,len[i]));
		cIdx+=len[i];
	}
	
	for(int i=0; i<n; i++)
	{
		long long v = strtol(value[i].c_str(),NULL,16);
		printf("%lld ",v);
	}
	
	return 0;
}
