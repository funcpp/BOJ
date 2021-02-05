#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	struct hubo{
		int idx=0;
		int s[5]={0,};
	};
	
	vector<hubo> _hb(4);
	
	int N;
	scanf("%d",&N);
	
	for(int i=0;i<3;i++){
		_hb[i].idx=i+1;
	}
	
	for(int i=0,a,b,c;i<N;i++){
		scanf("%d %d %d",&a,&b,&c);
		_hb[0].s[a]++;
		_hb[1].s[b]++;
		_hb[2].s[c]++;
	}
	
	sort(_hb.begin(), _hb.end(), [&](hubo a, hubo b) -> bool{
		int at = 3*a.s[3]+2*a.s[2]+1*a.s[1];
		int bt = 3*b.s[3]+2*b.s[2]+1*b.s[1];
		if(at==bt){
			if(a.s[3] == b.s[3]){
				if(a.s[2]==b.s[2]){
					return a.s[1]>b.s[1];	
				}
				return a.s[2]>b.s[2];
			}
			return a.s[3]>b.s[3];
		}
		return at>bt;
	}); 
	
	if(_hb[0].s[3]==_hb[1].s[3] && _hb[0].s[2]==_hb[1].s[2] && _hb[0].s[1]==_hb[1].s[1]){
		printf("0 %d",3*_hb[0].s[3]+2*_hb[0].s[2]+1*_hb[0].s[1]);
		return 0;
	} else{
		printf("%d %d",_hb[0].idx, 3*_hb[0].s[3]+2*_hb[0].s[2]+1*_hb[0].s[1]);
	}
	
	return 0;
}
