#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b,c;
	int answer[10]={0};
	scanf("%d %d %d",&a,&b,&c);
	
	int num=a*b*c;
	
	while(num>0)
	{
		answer[num%10]++;
		num /=10;
	}
	
	for(int i=0; i<10; i++)
	{
		printf("%d\n",answer[i]);
	}
	
	return 0;
}
 
