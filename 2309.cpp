#include <stdio.h>
#include <algorithm>
int main()
{
	int sum=0;
	int height[9];
	for(int i=0; i<9; i++)
	{
		scanf("%d",height+i);
		sum+=height[i];
	}
	std::sort(height,height+9);
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			if(i==j) continue;
			
			if(sum-height[i]-height[j]==100)
			{
				for(int k=0; k<9; k++)
				{
					if(k!=i && k!=j)
					{
						printf("%d\n",height[k]);
					}
				}
				return 0;
			}
		}
	}
	return 0;
}
