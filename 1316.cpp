#include <stdio.h>
#include <string.h>
int main()
{
	int N;
	int count=0;
	
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		char c[100];
		scanf("%s",c);
		int len=strlen(c);
		bool b[26]={false};
		int save=0;
		bool found=true;
		for(int j=0; j<len; j++)
		{
			if(!b[c[j]-97])
			{
				save=c[j]-97;
				b[c[j]-97]=true;
			}
			else if(save!=c[j]-97)
			{
				found=false;
				break;
			}
		}
		if(found)
			count++;
	}
	printf("%d",count);
	return 0;
}
