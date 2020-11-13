#include <stdio.h>
int arr[1005][1005];
int R,C,n;

int main()
{
	scanf("%d %d",&C,&R);
	scanf("%d",&n);
	if(n>R*C)
	{
		printf("0");
		return 0;
	}
	
	int x=R-1,y=0;
	int cnt=1, dir=1; //1À§·Î 2¿À¸¥ÂÊ 3¹ØÀ¸·Î 4¿Þ 
	while(cnt!=R*C)
	{
		if(cnt++==n)
		{
			printf("%d %d",C-x-1,y+1);
			break;
		}
		
		if(dir==1)
		{
			if(x==0)
			{
				dir=2; continue;
			}
			x--;
		}
		else if(dir==2)
		{
			if(y==C-1)
			{
				dir=3; continue;
			}
			y++;
		}
		else if(dir==3)
		{
			if(x==R-1)
			{
				dir=4;
				continue;
			}
			x++;
		}
		else if(dir==4)
		{
			if(y==0)
			{
				dir=1;
				continue;
			}
			y--;
		}
	}
	
	return 0;
}
