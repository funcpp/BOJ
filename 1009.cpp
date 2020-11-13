#include <stdio.h>
#define _ int
_ T,a,b,r;main(){scanf("%d",&T);while(T--){scanf("%d %d",&a,&b);r=a;b%=4;b+=3;while(b--)r=(r*a)%10;printf("%d\n",!r?10:r);}}
