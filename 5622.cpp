#include <stdio.h>
#include <string.h>
int main()
{
	char c[16];
	scanf("%s",c);
	int len=strlen(c);
	int num[len]={0};
	for(int i=0; i<len; i++)
	{
		if(*(c+i) >= 'A' && *(c+i) <= 'C')
			 num[i]=2;
		else if(*(c+i) >= 'D' && *(c+i) <= 'F')
			 num[i]=3;
		else if(*(c+i) >= 'G' && *(c+i) <= 'I')
			 num[i]=4;
		else if(*(c+i) >= 'J' && *(c+i) <= 'L')
			 num[i]=5;
		else if(*(c+i) >= 'M' && *(c+i) <= 'O')
			 num[i]=6;
		else if(*(c+i) >= 'P' && *(c+i) <= 'S')
			 num[i]=7;
		else if(*(c+i) >= 'T' && *(c+i) <= 'V')
			 num[i]=8;
		else if(*(c+i) >= 'W' && *(c+i) <= 'Z')
			 num[i]=9;
		else
			num[i]=0;
	}
	
	int sum=0;
	for(int i=0; i<len; i++)
	{
		if(num[i]==0)
			sum+=10;
		else
			sum+=num[i];
		
		sum+=1;
	}
	
	printf("%d\n",sum);
	return 0;
}
