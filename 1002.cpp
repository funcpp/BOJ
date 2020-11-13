#include <stdio.h>
#include <math.h>

int main()
{
	int T, x1, y1, r1, x2, y2, r2, i, bbae;
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		if (r1 > r2) bbae = r1 - r2;
		else bbae = r2 - r1;

		double distance = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));

		if(x1==x2&&y1==y2)
		{
			if(r1==r2)
				printf("-1\n");
			else
				printf("0\n");
		}
		else
		{
			if (distance < r1 + r2 && bbae < distance)
				printf("2\n");
			else if (distance == r1 + r2 || distance == bbae)
				printf("1\n");
			else
				printf("0\n");
		}
	}
	
	return 0;
}
