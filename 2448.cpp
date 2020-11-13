#include <stdio.h>

char arr[3072][6144];
void star(int n, int x, int y);

int main()
{
    int n, i, j;
    scanf("%d", &n);

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < 2*n;j++)
        {
            if(j==2*n)
                arr[i][j] = '\0';
            else
                arr[i][j] = ' ';

        }
    }

    star(n, n - 1, 0);
    
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < 2*n;j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}



void star(int n, int x, int y)
{
    if(n == 3)
    {
        arr[y][x]= '*';
        arr[y+1][x-1] = '*';
        arr[y+1][x+1] = '*';
        arr[y+2][x-2] = '*';
        arr[y+2][x-1] = '*';
        arr[y+2][x] = '*';
        arr[y+2][x+1] = '*';
        arr[y+2][x+2] = '*';
        return;
    }
    star(n/2, x, y);
    star(n/2, x - n/2, y + n/2);
    star(n/2, x + n/2, y + n/2);
}
