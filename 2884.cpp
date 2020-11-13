#include <stdio.h>
int main()
{
	int H,M;
	scanf("%d %d",&H,&M);
	
	int ans = H*60+M-45;
	H=ans/60;
	M=ans-((ans/60)*60);
	if(H==0 && M<0)
	{
		H=23;
		M=60+M;
	}
	printf("%d %d", H, M);
}
