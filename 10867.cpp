#include <bits/stdc++.h>
using namespace std;
int main(){int n;scanf("%d",&n);vector<int> v(n,0);for(int i=0;i<n;i++)scanf("%d",&v[i]);sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());for(auto it=v.begin();it!=v.end();it++)printf("%d ",*it);}
