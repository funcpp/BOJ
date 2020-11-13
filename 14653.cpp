#include <stdio.h>

struct Msg
{
	int r;
	char p;
};

int main()
{
	int n,k,q;
	scanf("%d %d %d",&n,&k,&q);
	bool read[100];
	Msg msg[10005];
	
	for(int i=0; i<k; i++)
	{
		scanf("%d %c",&msg[i].r,&msg[i].p);
	}
	
	int notRead = msg[q-1].r;
	if(notRead==0)
	{
		printf("-1");
		return 0;
	}
	
	for(int i=0; i<k; i++)
	{
		if(notRead <= msg[i].r)
		{
			read[msg[i].p-65]=true;
		}
	}
	
	for(int i=1; i<n; i++)
	{
		if(!read[i]) printf("%c ",char(i+65));
	}
	
	return 0;
}
