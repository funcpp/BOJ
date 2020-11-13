#include <stdio.h>
int num[10];
int main()
{
	int n;
	scanf("%d",&n);
	if(n==0) num[0]++;
	while(n!=0)
	{
		if(n==0)
		{
			num[0]++;
			break;
		}
		num[n%10]++;
		n/=10;
	}
	num[6]+=num[9];
	num[9]=0;
	
	//printf("%d b\n",num[6]/2);
	if(num[6]%2==1)
	{
	//num[6]/=2;
	num[6]+=1;
	}	
	num[6]/=2;
		
	//printf("%d a\n",num[6]);
	
	int ans=0;
	for(int i=0; i<10; i++)
	{
		if(ans < num[i])
		{
			ans= num[i];
			//printf("%d %d",i,num[i]);
		}
	}
	printf("%d",ans);
	return 0;
}
