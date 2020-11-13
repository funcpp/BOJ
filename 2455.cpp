#include <stdio.h>
int main()
{
	int human=0;
	int max=0;
	for(int i=0; i<4; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		human+=b-a;
		
		if(max < human)
		{
			max=human;
		}
	}
	printf("%d\n",max);
	return 0;
}
