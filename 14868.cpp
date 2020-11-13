#include <stdio.h>
#include <queue>

using namespace std;

int prt[100005];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int map[2005][2005];

int N,K;
int MoonCnt=0;

struct Point
{
	int x,y;
};

queue<Point> q;
 
int find(int a)
{
	if(a==prt[a]) return a;
	return prt[a] = find(prt[a]);
}

bool merge(int a, int b) // a>b
{
	a = find(a);
	b = find(b);
	if(a==b) return true;
	prt[a]=b;
	
	return false;
}

/*
bool isEqual(int a, int b)
{
	return find(a)==find(b);	
}*/

int main()
{
	scanf("%d %d",&N,&K);
	
	for(int i=0; i<=100000; i++)
	{
		prt[i]=i;
	}
	
	for(int i=0; i<K; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		map[x][y]=++MoonCnt;
		q.push({x,y});
	}
	
	int ans=0;
	while(MoonCnt)
	{
		queue<Point> q2;
		
		while(!q.empty())
		{
			Point pt = q.front();
			q.pop();
			q2.push(pt);
			
			int x = pt.x;
			int y = pt.y;
			
			for(int i=0; i<4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx>0 && nx<=N && ny>0 && ny<=N)
				{
					if(map[nx][ny] && map[x][y]!=map[nx][ny]) 
					{
						//if(!isEqual(map[x][y],map[nx][ny]))
						if(!merge(map[x][y],map[nx][ny]))
						{
							//merge(map[x][y],map[nx][ny]);
							MoonCnt--;
						}
					}
				}
			}
		}
		
		//printf("C : %d\n",MoonCnt);
		if(MoonCnt==1)
		{
			printf("%d",ans);
			break;
		}
		
		while(!q2.empty())
		{
			Point pt = q2.front();
			q2.pop();
			
			int x = pt.x;
			int y = pt.y;
			
			for(int i=0; i<4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx>0 && nx<=N && ny>0 && ny<=N)
				{
					if(!map[nx][ny]) //X 
					{
						map[nx][ny]=map[x][y];
						q.push({nx,ny}); 
					}
					else if(map[nx][ny]>0 && map[x][y]!=map[nx][ny])
					{
						//if(!isEqual(map[x][y],map[nx][ny]))
						if(!merge(map[x][y],map[nx][ny]))
						{
							//merge(map[x][y],map[nx][ny]);
							MoonCnt--;
						}
					}
				}
			}
		}
		
		ans++;
	}
	
	return 0;	
}
