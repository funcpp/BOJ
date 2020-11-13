#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
	int x, y;
};

int R,C;
int map[1505][1505];
bool chk[1505][1505];
	
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main()
{
	scanf("%d %d",&R,&C);
	
	vector<Point> bird;
	queue<Point> water;
	
	for(int i=0; i<R; i++)
	{
		char s[C+5];
		scanf("%s",s);
		
		for(int j=0; j<C; j++)
		{
			if(s[j]=='.')
			{
				map[i][j]=0;
				water.push({i,j});
			}
			else if(s[j] == 'L')
			{
				map[i][j]=2;
				water.push({i,j});
				bird.push_back({i,j});
			}
			else if(s[j]=='X')
			{
				map[i][j]=1;
			}
		}
	}
	
	queue<Point> q;
	q.push(bird[0]);
	
	int ans=0;
	chk[bird[0].x][bird[0].y]=1;
	
	while(true)
	{
		queue<Point> willMelt;
		bool b=false;
		
		while(!q.empty())
		{
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			
			if(x==bird[1].x && y==bird[1].y)
			{
				b=true;
				break;
			}
			
			for(int i=0; i<4; i++)
			{
				int nx= x + dx[i];
				int ny= y + dy[i];
				
				if(nx>=0 && nx<R && ny>=0 && ny<C && !chk[nx][ny])
				{
					chk[nx][ny]=1;
					
					if(map[nx][ny]==1)
					{
						willMelt.push({nx,ny});
						continue;
					}
					
					q.push({nx,ny});
				}
			}
		}
		
		if(b) break;
		
		q=willMelt;
		
		int waterCnt=water.size();
		
		while(waterCnt--)
		{
			int x = water.front().x;
			int y = water.front().y;
			water.pop();
			
			for(int i=0; i<4; i++)
			{
				int nx= x + dx[i];
				int ny= y + dy[i];
				
				if(nx>=0 && nx<R && ny>=0 && ny<C)
				{
					if(map[nx][ny]==1)
					{
						map[nx][ny]=0;
						water.push({nx,ny});
					}
				}
			}
		}
		
		ans++;
	}
	
	printf("%d",ans);
	return 0;
}
