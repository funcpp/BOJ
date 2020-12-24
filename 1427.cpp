#include<bits/stdc++.h>
int main(){
	int n;
	scanf("%d",&n);
	std::vector<int> v;
	while(n){
		v.push_back(n%10);
		n/=10;
	}
	std::sort(v.begin(), v.end());
	for(auto it =v.end()-1;it>=v.begin();it--){
		printf("%d",*it);
	}
}
