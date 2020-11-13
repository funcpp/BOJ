#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	char c[100]={0,};
	scanf("%s",c);
	int answer=0;
	
	for(int i=0; i<n; i++)
	{
		answer += c[i]-'0';
	}
	
	printf("%d\n",answer);
	return 0;
}
