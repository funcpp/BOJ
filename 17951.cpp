#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int N,K, ans;
vector<int> v;
bool can(int c)
{
	int now = 0, cnt = 0, m = 1e9;
	for(int i=0;i<N;i++){
		if(now + v[i] >=c){
			cnt++;
			m=min(m,now+v[i]);
			now=0;
			if(cnt>=K){
				ans=max(ans,m);
				return true;
			}
		}
		else{
			now+=v[i];
		}
	}
	return false;
}
int main()
{
	scanf("%d %d",&N,&K);
	v = vector<int>(N+5,0);
	for(int i=0;i<N;i++){
		scanf("%d",&v[i]);
	}
	int left =  0, right = 1e9, mid;
	while(left <= right){
		mid = (left+right)/2;
		//printf("%d %d %d\n",left,right,mid);
		if(can(mid)){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	printf("%d",ans);
	return 0;
}
