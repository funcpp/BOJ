#include <stdio.h>
int main()
{
	
	int mosun[10]={0,};
	for(int i=0; i<9; i++)
	{
		int ilrusu,number;
		scanf("%d %d",&ilrusu,&number);
		for(int j=1; j<=9; j++)
		{
			if(j==number && ilrusu==0)
			{
				mosun[j]++;
			}
			else if(j!=number && ilrusu==1)
			{
				mosun[j]++;
			}
		}
	}
	
	bool mosunfind=false;
	int ans=-1;
	for(int i=1; i<=9; i++)
	{
		if(mosun[i]==1 && mosunfind)
		{
			ans=-1;
			break;
		}
		if(mosun[i]==1)
		{
			mosunfind=true;
			ans=i;
		}
	}
	printf("%d",ans);
	return 0;
}
