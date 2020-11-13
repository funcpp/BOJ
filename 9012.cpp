#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		char s[55];
		scanf("%s",s);
		int len=strlen(s);
		int cnt=0;
		bool yes=true;
		for(int j=0; j<len; j++)
		{
			if(s[j]=='(') cnt++;
			else if(s[j]==')') cnt--;
			
			if(cnt<0)
			{
				yes=false;
				break;
			}
		}
		if(cnt!=0) yes=false;
		
		printf("%s\n",yes?"YES":"NO");
	}
	return 0;
}
