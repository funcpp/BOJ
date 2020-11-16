#include <stdio.h>
#include <vector>
using namespace std;

#define notX(x) (x^1)
#define trueX(x) (x<<1)
#define falseX(x) (x<<1|1)

int N,M;
vector<vector<int>> edge, SCC;

int counter;
vector<int> id, sccid, stack;

int tarjan(int u)
{
	int ret = id[u] = ++counter;
	stack.push_back(u);
	
	for(int v : edge[u]){
		if(id[v] == -1) ret = min(ret, tarjan(v));
		else if(sccid[v] == -1) ret = min(ret, id[v]);
	}
	
	if(ret == id[u])
	{
		SCC.push_back(vector<int>());
		while(1){
			int v = stack.back(); stack.pop_back();
			sccid[v] = SCC.size()-1;
			SCC.back().push_back(v);
			
			if(u==v) break;
		}
	}
	
	return ret;
}

int main()
{
	scanf("%d %d",&N,&M);
	
	edge = vector<vector<int>>(N+1<<1, vector<int>());
	id = vector<int>(N+1<<1, -1);
	sccid = vector<int>(N+1<<1, -1);
	
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		
		a = a>0 ? trueX(a) : falseX(-a);
		b = b>0 ? trueX(b) : falseX(-b);
		
		edge[notX(a)].push_back(b);
		edge[notX(b)].push_back(a);
	}
	
	for(int i=2;i<=N*2+1;i++)
	{
		if(id[i] == -1) tarjan(i);
	}
	
	bool mosun = false;
	for(int i=1;i<=N;i++){
		if(sccid[trueX(i)] == sccid[falseX(i)]){
			mosun=true;
			printf("0");
			break;
		}
	}
	if(!mosun)
	{
		printf("1\n");
		for(int i=1;i<=N;i++){
			if(sccid[trueX(i)] < sccid[falseX(i)]) printf("1 ");
			else printf("0 ");
		}
	}
	return 0;
}
