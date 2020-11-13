#include <stdio.h>

struct Work
{
	int days, money;	
};

int main()
{
	int n;
	scanf("%d",&n);
	
	Work work[n+5]={0,};
	for(int i=1; i<=n; i++)
	{
		scanf("%d %d",&work[i].days,&work[i].money);
	}
	
	int dp[n+5]={0,}; // n�Ͽ� �������մ��ִ뵷 
	
	for(int i=n; i>0; i--)
	{
		int d = i+work[i].days;//����+�ϱⰣ 
		if(d>n+1) //n+1���� ũ�� ������ 
		{
			dp[i]=dp[i+1];
		}
		else
		{
			dp[i]=dp[i+1]<dp[d]+work[i].money?dp[d]+work[i].money:dp[i+1];
			//���������� ���ϰ� �����°� ũ�� �ֱ� 
		}
	}
	
	printf("%d",dp[1]);
	
	return 0;
}
