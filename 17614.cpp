#include<stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	int ans=0;
	for(int i=1;i<=N;i++){
		int t=i;
		while(t){
			if(t%10>0 && (t%10)%3==0)ans++;
			t/=10;
		}
	}
	printf("%d",ans);
	return 0;
}
