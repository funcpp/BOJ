#include <stdio.h>
#include <math.h>
#define max(a,b) a<b?b:a

int map[30][30];
int floyd[900][900];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main()
{
	int N,M,T,D;
	scanf("%d %d %d %d",&N,&M,&T,&D);
	for(int i=0; i<N; i++)
	{
		char s[M+1];
		scanf("%s",s);
		for(int j=0; j<M; j++)
		{
			if('A'<= s[j] && s[j] <= 'Z')
			{
				map[i][j]=s[j]-'A';
			}
			else if('a'<=s[j]&&s[j]<='z')
			{
				map[i][j]=s[j]-'a'+26;
			}
		}
	}
	
	int MAX = N*M;
	
	for(int i=0; i<MAX; i++)
	{
		for(int j=0; j<MAX; j++)
		{
			if(i==j) continue;
			floyd[i][j]=987654321;
		}
	}
		
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			int h = i*M+j;
			for(int k=0; k<4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				
				if(nx>=0 && nx<N && ny>=0 && ny<M)
				{
					int n = nx * M + ny;
					int d = map[i][j] - map[nx][ny];
					
					if(abs(d)>T) continue;
					if(d>0) floyd[h][n]=1;
					else if(d<0) floyd[h][n]=d*d;
					else floyd[h][n]=1;
				}
			}
		}
	}
	
	for(int k=0; k<MAX; k++)
	{
		for(int i=0; i<MAX; i++)
		{
			for(int j=0; j<MAX; j++)
			{
				if(floyd[i][j] > floyd[i][k] + floyd[k][j])
				{
					floyd[i][j] = floyd[i][k] + floyd[k][j];
				}
			}
		}
	}
	
	int ans=0;
	
	for(int i=0; i<MAX; i++)
	{
		if(floyd[0][i] + floyd[i][0] <= D)
		{
			ans = max(ans,map[i/M][i%M]);
		}
	}
	printf("%d\n",ans);
	
	return 0;
}
