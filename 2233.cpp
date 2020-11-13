#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define MAX 2005

int N;
string s;
int X,Y;
vector<int> tree[MAX];
int main()
{
	scanf("%d",&N);
	cin >> s;
	scanf("%d %d",&X,&Y);
	
	vector<int> prtV;
	prtV.push_back(1);
	int parent=1;
	int prt=1;
	int child=0;
	
	for(int i=0; i<N*2; i++)
	{
		if(s.substr(i,1)=="0")
		{
			prtV.push_back(parent);
			tree[parent].push_back(prtV.back());
			//printf("0 %d\n",parent);
			
			parent++;
		}
		else
		{
			//printf("1 %d\n",prtV.back());
			prtV.pop_back();
		}
		
	}
	
	for(int i=1; i<N; i++)
	{
		printf("%d : ",i);
		for(int j=0;j<tree[i].size(); i++)
			printf("%d ",tree[i][j]);
		printf("\n");
	}
	
	
	return 0;
}
