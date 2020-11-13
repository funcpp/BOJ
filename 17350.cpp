#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	scanf("%d",&n);
	bool find=false;
	for(int i=0; i<n; i++)
	{
		char c[100];
		scanf("%s",c);
		if(strcmp(c,"anj")==0)
		{
			find=true;
		}
		/*int len = strlen(c);
		for(int j=0; j<len; j++)
		{
			if(j<len-2 && c[j]=='a' && c[j+1]=='n' && c[j+2]=='j')
			{
				find=true;
				break;
			}
		}*/
		if(find) break;
	}
	
	if(find) printf("构具;\n");
	else printf("构具?\n");
} 
