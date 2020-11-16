#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

#define trueX(x) (x<<1)
#define falseX(x) (x<<1|1)
#define notX(x) (x^1)

int N,M;
vector<vector<int>> edge, redge, SCC;
vector<int> SCCN;

void makeSCC()
{
	unordered_map<int, bool> chk;
	vector<int> st;
	auto dfs1 = [&](int idx, auto func)->void{
		for(int nx : edge[idx]){
			if(!chk.count(nx)){
				chk[nx]=true;
				func(nx,func);
			}
		}
		st.push_back(idx);
	};
	auto dfs2 = [&](int idx, auto func)->void{
		for(int nx : redge[idx]){
			if(!chk.count(nx)){
				chk[nx]=true;
				func(nx,func);
			}
		}
		SCC.back().push_back(idx);
		SCCN[idx] = SCC.size()-1;
	};
	for(int i=2; i<=2*M+1; i++){
		if(!chk.count(i)){
			chk[i]=true;
			dfs1(i,dfs1);
		}
	}
	chk.clear();
	for(int i=st.size()-1; i>=0;i--){
		if(!chk.count(st[i])){
			chk[st[i]]=true;
			SCC.push_back(vector<int>());
			dfs2(st[i],dfs2);
		}
	}
}



int main(){
	scanf("%d %d",&N,&M);
	edge = vector<vector<int>>(M+1<<1, vector<int>());
	redge = vector<vector<int>>(M+1<<1, vector<int>());
	SCCN =  vector<int>(M+1<<1, 0);
	SCC.clear();
	
	for(int i=0;i<N;i++){
		int a, b;
		scanf("%d %d",&a,&b);
		//a번쨰에 true를 / b 번쨰에 false를 낸다 ... 이런식
		//하나의 절 = (a || ~b) 이런식
		// 가위바위보의 횟차수 =========== 변수
		// 가위or바위 == 참트루 or 거짓 
		 
		a = a>0 ? trueX(a) : falseX(-a);
		b = b>0 ? trueX(b) : falseX(-b);
		
		edge[notX(a)].push_back(b);
		edge[notX(b)].push_back(a);
		
		redge[a].push_back(notX(b));
		redge[b].push_back(notX(a));	
	}
	
	makeSCC();
	
	bool b = true;
	for(int i=1;i<=M;i++){
		if(SCCN[trueX(i)] == SCCN[falseX(i)]){ //i번째에 한 학생은 뒤지고 한 학생은 사는 경우가 .-... -> 뒤짐 
			b=false;
			break;
		}
	}
	printf("%s\n", b ?  "^_^" : "OTL");
}
