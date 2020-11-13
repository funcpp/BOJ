#include <stdio.h>

int save(int num);

int main()
{
	int j;
	bool self[10002]={false,};
	for(int i=1; i<10001; i++)
	{
		j=save(i);
		if(j <= 10001)
		{
			self[j] = true;
		}
	}
	
	for(int i=1; i<10001; i++)
	{
		if(!self[i])
			printf("%d\n",i);
	}
	
	return 0;
}

int save(int num)
{
	int sum=num;
	
	while(true)
	{
		if(num==0) break;
		sum+=num%10;
		num /=10;
	}
	
	return sum;
}
