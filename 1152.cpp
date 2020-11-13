#include <stdio.h>

int main()
{
	int count=0;
	char c[1000001] = {32,};
	bool gong=true;
	
	scanf("%[^\n]s",&c);
	for(int i=0; c[i]!='\0'; i++)
	{	
		if(c[i] == 32) gong=true;
		else if(gong)
		{
			gong=false;
			count++;
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}
