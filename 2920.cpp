#include <stdio.h>
int main()
{
	int a[8]={0};
	int asc[8]={1,2,3,4,5,6,7,8};
	int des[8]={8,7,6,5,4,3,2,1};
	for(int i=0; i<8; i++)
		scanf("%d",a+i);
	
	int answer;
	int cor=0;
	for(int i=0; i<8; i++)
	{
		if(a[i]==asc[i])
			cor++;
		else if(a[i]==des[i])
			cor--;
	}
	
	if(cor==8)
		printf("ascending\n");
	else if(cor==-8)
		printf("descending");
	else
		printf("mixed");
		
	return 0;
}
