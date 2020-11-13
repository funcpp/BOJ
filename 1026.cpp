#include <stdio.h>
#include <algorithm>

bool cmp(int a, int b) {return a>b;};

int main()
{
	int n;
	scanf("%d",&n);
	int A[n], B[n], B2[n], idx[n];
	
	for(int i=0; i<n; i++)
		scanf("%d",A+i);
	
	for(int i=0; i<n; i++)
		scanf("%d",B+i);
	
	std::sort(A,A+n);
	std::sort(B,B+n,cmp);
	
	int ans=0;
	for(int i=0; i<n; i++)
	{
		ans+=A[i]*B[i];
	}
	printf("%d",ans);
	return 0;
}
