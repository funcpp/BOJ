#include<stdio.h>
#define _ int
_ N,M,K,i,j,a,c,X,Y,t,p,m[101][101],Q[4]={1,-1,0,0},W[4]={0,0,1,-1},v[101][101];void d(_ x,_ y, _& c){v[x][y]=1;c++;for(_ i=0;i<4;i++){X=x+Q[i];Y=y+W[i];if(!v[X][Y]&&m[X][Y])d(X,Y,c);}}main(){scanf("%d %d %d",&N,&M,&K);while(K--){scanf("%d %d",&t,&p);m[t][p]=1;}for(i=0;i<=N;i++)for(j=0;j<=M;j++)if(!v[i][j]&&m[i][j]){c=0;d(i,j,c);a=a<c?c:a;}printf("%d",a);}
