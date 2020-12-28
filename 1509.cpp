#include <bits/stdc++.h>
using namespace std;

int dp[2505][2505];
int dp2[2505];

int main()
{
	string s;
	cin >> s;
	
	int len = s.size();
	
	for(int i=0;i<len;i++){
		dp[i][i]=1;
	}
	
	for(int i=0;i<len-1;i++){
		if(s[i]==s[i+1]) dp[i][i+1]=2;
	}

	for(int i=1;i<len;i++){
		for(int j=0;j<len-i;j++){
			if(s[j]==s[j+i] && dp[j+1][j+i-1]) dp[j][j+i]=1;
		}
	}

	for(int i=0;i<len;i++){ //e
		dp2[i]=0x7f7f7f7f;
		for(int j=0;j<=i;j++){ //s
			if(dp[j][i]) dp2[i]=min(dp2[i], dp2[j-1]+1);
		}
	}
	
	printf("%d",dp2[len-1]);
	return 0;
}
