#include <stdio.h>
#include <string.h>
#include <algorithm>

int main()
{
	char s[15];
	scanf("%s",s);
	
	int len = strlen(s);
	int num[len];
	for(int i=0; i<len; i++)
	{
		num[i]=s[i]-'0';
	}
	
	std::sort(num,num+len);
	for(int i=len-1; i>=0; i--)
	{
		printf("%d",num[i]);
	}
	return 0;
} 
