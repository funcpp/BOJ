#include<stdio.h>


int fibof(int n);
int fibo[41]={1,1};

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0; i<T; i++)
	{
		int t2;
		scanf("%d",&t2);
		if(t2==0)	printf("1 0\n");
		else if(t2==1)	printf("0 1\n");
		else
		{
			fibof(t2);
			printf("%d %d\n",fibo[t2-1],fibo[t2]);
		}
	}
	return 0;
}

int fibof(int n)
{
	if(n==0 || n==-1)
	{
		fibo[0]=0;
		return 0;
	}
	else if(n==1)
	{
		fibo[1]=1;
		return 1;
	}
	
	if(fibo[n]!=0)
	{
		return fibo[n];
	}
	else
	{
		return fibo[n] = fibof(n-1) + fibof(n-2);
	}
}
