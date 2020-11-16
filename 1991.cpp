#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

struct Node
{
	int prt, ch1, ch2;
};

int N;
Node node[30];
vector<char> ans;
map<char, bool> chk;

void preorder(int idx)
{
	chk[idx]=true;
	ans.push_back(idx+'A');
	
	if(node[idx].ch1!='.'-'A' && !chk.count(node[idx].ch1))
	{
		preorder(node[idx].ch1);
	}
	
	if(node[idx].ch2!='.'-'A' && !chk.count(node[idx].ch2))
	{
		preorder(node[idx].ch2);
	}
	
	return;
}

void inorder(int idx)
{
	chk[idx]=true;
	
	if(node[idx].ch1!='.'-'A' && !chk.count(node[idx].ch1))
	{
		inorder(node[idx].ch1);
	}
	
	ans.push_back(idx+'A');
	
	if(node[idx].ch2!='.'-'A' && !chk.count(node[idx].ch2))
	{
		inorder(node[idx].ch2);
	}
	
	
	return;
}

void postorder(int idx)
{
	chk[idx]=true;
	
	if(node[idx].ch1!='.'-'A' && !chk.count(node[idx].ch1))
	{
		postorder(node[idx].ch1);
	}
	
	if(node[idx].ch2!='.'-'A' && !chk.count(node[idx].ch2))
	{
		postorder(node[idx].ch2);
	}
	
	ans.push_back(idx+'A');
	return;
}

int main()
{
	scanf("%d",&N); 
	
	for(int i=0; i<N; i++)
	{
		char prt, ch1, ch2;
		scanf(" %c %c %c",&prt,&ch1,&ch2);
		
		node[prt-'A'].ch1=ch1-'A';
		node[prt-'A'].ch2=ch2-'A';
		if(ch1!='.') node[ch1-'A'].prt = prt-'A';
		if(ch2!='.') node[ch2-'A'].prt = prt-'A';
	}
	
	preorder(0);
	for(int i=0; i<ans.size(); i++) printf("%c",ans[i]);
	printf("\n");
	chk.clear();
	ans.clear();
	
	inorder(0);
	for(int i=0; i<ans.size(); i++) printf("%c",ans[i]);
	printf("\n");
	chk.clear();
	ans.clear();
	
	postorder(0);
	for(int i=0; i<ans.size(); i++) printf("%c",ans[i]);
	printf("\n");
	chk.clear();
	ans.clear();
	
	return 0;
}
