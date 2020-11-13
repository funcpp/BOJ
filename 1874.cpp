#include <stdio.h>
int stack[1000001];
int size=-1;
void push(int n)
{
	size++;
	stack[size]=n;
}

int pop()
{
	return stack[size--];	
}

int topf()
{
	return stack[size];
}
int main()
{
	int len,max=0,value=1;
	scanf("%d",&len);
	char ans[1000001]={0};
	int index=0;
	bool fuck=false;
	for(int i=0; i<len; i++)
	{
		int input;
		scanf("%d",&input);
		
		
		if(max<input)
		{
			max=input;
			while(value<=input)
			{
				push(value);
				ans[index++]='+';
				value++;
			}
			pop();
			ans[index++]='-';
			//value--;
		}
		else
		{
			if(input == topf())
			{
				pop();
				ans[index++]='-';
				//value--;
			}
			else
			{
				//printf("NO(max:%d)\n",max);
				fuck=true;
			}
		}
	}
	
	if(fuck)
	{
		printf("NO\n");
		return 0;
	}
	for(int i=0; i<index; i++)
	{
		printf("%c\n",ans[i]);
	}
	
	return 0;
}
