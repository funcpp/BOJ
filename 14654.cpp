#include <stdio.h>

int game(int n, int m)
{
	if(n==m) return 3;
	
	if(n==1 && m==2) return 2;
	if(n==2 && m==3) return 2;
	if(n==3 && m==1) return 2;
	
	return 1;
} 

int main()
{
	int n;
	scanf("%d",&n);
	
	int info[n+1];
	int info2[n+1];
	
	for(int i=0; i<n; i++)
		scanf("%d",info+i);
	
	for(int i=0; i<n; i++)
		scanf("%d",info2+i);
	
	int ans=0;
	int cnt1=0, cnt2=0;
	
	for(int i=0; i<n; i++)
	{
		int res = game(info[i],info2[i]);
		
		if(res==3)
		{
			if(cnt1==0)
			{
				cnt1++;
				ans=ans<cnt1?cnt1:ans;
				cnt2=0;
			}
			else
			{
				cnt2++;
				ans=ans<cnt2?cnt2:ans;
				cnt1=0;
			}
		}
		else if(res==1)
		{
			cnt1++;
			ans=ans<cnt1?cnt1:ans;
			cnt2=0;	
		}
		else if(res==2)
		{
			cnt2++;
			ans=ans<cnt2?cnt2:ans;
			cnt1=0;
		}
	}
	
	printf("%d",ans);
	
	return 0;
}
