#include <stdio.h>
int returnF(int num);

int main()
{
	int num,tnum,count=0,save;
	scanf("%d",&num);
	save=num;
	tnum=num;
	
	while(true)
	{
		tnum=returnF(tnum);
		count++;
		if(tnum==save)
		{
			break;
		} 
	}
	printf("%d\n",count);
	
	return 0;
}

int returnF(int num)
{
	return num%10*10+(num%10+num/10)%10;
}
