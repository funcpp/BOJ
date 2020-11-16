#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;
#define MAX 100005

int N,M,A,B;
vector<int> edge[MAX];
unordered_map<int, bool> visited;
vector<int> stack;
void dfs(int idx, bool push=0) {
	visited[idx]=true;
	for(int x : edge[idx]) {
		if(!visited.count(x)) {
			dfs(x, push);
		}
	}
	if(push) stack.push_back(idx);
}

int main() {
	scanf("%d %d",&N, &M);
	while(M--){
		scanf("%d %d",&A,&B);
		edge[A].push_back(B);
	}
	for(A=0;A<N;A++) if(!visited.count(A)) dfs(A,true);
	visited.clear(); B=0;
	for(A=N-1;A>=0;A--) if(!visited.count(stack[A])){
		dfs(stack[A]);
		B++;
	}
	printf("%d",B);
	return 0;
}
