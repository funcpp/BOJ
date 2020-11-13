#include <stdio.h>
#include <algorithm>

using namespace std;

int floyd[505][505];
int floyd2[505][505];

struct Info
{
	int t;
	int idx;
	
	bool operator < (const struct Info& v)
	{
		return t<v.t;	
	}	
};

int main()
{
	int N,M,Q;
	scanf("%d %d %d",&N,&M,&Q);

	int time[N+1];
	Info info[N+1];
	
	for(int i=0; i<=N; i++)
	{
		for(int j=0; j<=N; j++)
		{
			floyd[i][j]=987654321;
			floyd2[i][j]=0;
		}
	}
	
	for(int i=1; i<=N; i++)
	{
		scanf("%d",time+i);
		info[i-1]={time[i],i};
	}
	
	while(M--)
	{
		int a,b,d;
		scanf("%d %d %d",&a,&b,&d);
		
		floyd[a][b] = d;
		floyd[b][a] = d;
	}
	
	for(int i=1; i<=N; i++) floyd[i][i]=0;
	
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			if(i==j) floyd2[i][j]=0;
			else floyd2[i][j]=floyd[i][j]+max(info[i-1].t,info[j-1].t);
		}
	}
	
	std::sort(info,info+N);
	for(int j=0; j<N; j++)
	{
		int w = info[j].idx;
		int t = info[j].t;
		
		for(int i=1; i<=N; i++)
		{
			for(int k=1; k<=N; k++)
			{
				floyd[i][k] = min(floyd[i][k],floyd[i][w]+floyd[w][k]);
				floyd2[i][k] = max(floyd[i][k]+max(time[i],time[k]),min(floyd2[i][k],floyd[i][w]+t+floyd[w][k]));
			}
		}
	}
	
	while(Q--)
	{
		int S,T;
		scanf("%d %d",&S,&T);
		printf("%d\n",floyd2[S][T]>=987654321 ? -1 : floyd2[S][T]);
	}
	
	return 0;
}
