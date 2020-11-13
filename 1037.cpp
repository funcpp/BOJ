#include <stdio.h>
#include <stdlib.h>
 
int main()
{
      int num,i,j;
    scanf("%d",&num);
     int *prime =(int *)malloc(sizeof(int)*num);
 
     for(i=0; i<num; i++)
     {
         scanf("%d%*c",&prime[i]);
    }
    
    for(i=0; i<num-1; i++)
    {
        for(j=0; j<num-1; j++)
        {
            if(prime[j]>prime[j+1])
            {
                int tmp; 
                tmp = prime[j];
                prime[j] = prime[j+1];
                prime[j+1] = tmp;
            }
        }
    }
    printf("%d",prime[0]*prime[num-1]);
}

