#include <stdio.h>
#include <string.h>
 
int main()
{
    char c[1000000];
    int i, len, j, count, max, a=0,k;
    int times[26];
 
    scanf("%s", c);
    len = strlen(c);
 
    for (j = 65; j < 91; j++)
    {
        count = 0;
        for (i = 0; i < len; i++)
        {
            if (c[i] == j || c[i] == j + 32)
            {
                count++;
            }
        }
        times[j - 65] = count;
    }
 
    max = times[0];
    for (i = 1; i < 26; i++)
    {
        if (max < times[i])
        {
            max = times[i];
        }
    }
    for (i = 0; i < 26; i++)
    {
        if (max == times[i])
        {
            a++;
            k = i;
        }
    }
 
    if (a == 1)
    {
        printf("%c \n", k+65);
    }
    else if(a>1)
        printf("? \n");
        
    return 0;
}
