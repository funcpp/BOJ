#include <stdio.h>
int min(int a, int b);
int main()
{
	int n;
	scanf("%d",&n);
	if(n==1){
		printf("0\n");
		return 0;
	}
	int ans[n+1]={0};
	
	ans[1]=0;
	for(int i=2; i<=n; i++)
	{
		ans[i]=ans[i-1]+1;
		if(i%3==0)
		{
			ans[i]=min(ans[i],ans[i/3]+1);
		}
		else if(i%2==0){
			ans[i]=min(ans[i],ans[i/2]+1);
		}
	}
	printf("%d\n",ans[n]);
	return 0;
}

int min(int a, int b)
{
	return a>b ? b : a;
}
