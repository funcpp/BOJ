#include <stdio.h>
#include <memory.h>

int n,m;
int map[55][55];
int mapSet[8][8];

int count(int x, int y)
{
	if(x+7>=n || y+7>=m) return 987654321;
			
	int num=0, num1=0;
	
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			if((i+j)%2==0)
			{
				if(map[x+i][y+j] != 1) num++;
				else num1++;
			}
			else
			{
				if(map[x+i][y+j] != 0) num++;
				else num1++;
			}
		}
	}
	
	return (num < num1) ? num : num1;
}

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int i=0; i<n; i++)
	{
		char s[m+5];
		scanf("%s",s);
		
		for(int j=0; j<m; j++)
		{
			map[i][j]= (s[j]=='W') ? 1 : 0;
		}
	}
	int ans=987654321;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{	
			int c=count(i,j);
			ans = ans < c ? ans : c;
		}
	}
	printf("%d",ans);
	return 0;
}
