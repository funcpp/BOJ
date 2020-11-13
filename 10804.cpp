#include <stdio.h>
void swap(int& a,int &b)
{
	int t=a;
	a=b;
	b=t;
}

int main()
{
	int arr[21]={0,};
	for(int i=1;i<=20;i++)
	{
		*(arr+i)=i;
	}
	
	for(int i=0;i<10;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		int g=(b-a)&1?(b-a)/2+1:(b-a)/2;
		for(int j=0;j<g;j++)
		{
			swap(arr[a+j],arr[b-j]);
		}
	}
	
	for(int i=1; i<=20; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
