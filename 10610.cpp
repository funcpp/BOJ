#include <stdio.h>
#include <string.h>
#include <algorithm>
int main()
{
	char s[100005];
	scanf("%s",s);
	int len=strlen(s);
	int nums[len];
	int sum=0;
	bool hadZero=false;
	for(int i=0; i<len; i++)
	{
		if(s[i]=='0') hadZero=true;
		sum += s[i]-'0';
		nums[i] = s[i]-'0';
	}
	if(sum%3==0 && hadZero)
	{
		std::sort(nums,nums+len);
		for(int i=len-1; i>=0; i--)
		{
			printf("%d",nums[i]);
		}
	}
	else
	{
		printf("-1");
	}
	return 0;
}
