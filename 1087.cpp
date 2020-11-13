#include <stdio.h>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct mouse
{
	pair<int,int> pos;
	pair<int,int> velocity;
};

int N;
mouse mou[55];

double GetL(double t)
{
	double maxX=-1e9,maxY=-1e9,minX=1e12,minY=1e12;
	
	for(int i=0; i<N; i++)
	{
		pair<double,double> pos = make_pair(mou[i].pos.first + (mou[i].velocity.first * t), mou[i].pos.second + (mou[i].velocity.second * t));
		if(pos.first > maxX) maxX=pos.first;
		if(pos.first < minX) minX=pos.first;
		if(pos.second > maxY) maxY=pos.second;
		if(pos.second < minY) minY=pos.second;
	}
	
	return max(fabs(maxX-minX),fabs(maxY-minY));
}



int main()
{
	scanf("%d",&N);
	
	for(int i=0; i<N; i++)
	{
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		mou[i].pos={a,b};
		mou[i].velocity={c,d};
	}
	
	double left=0, right=2000, midleft, midright;
	
	while(left<right)
	{
		midleft = left + (right-left)/3.f;
		midright = left + (right-left)/3.f * 2;
		
		double l = GetL(midleft), r = GetL(midright);
		if(l < r)
		{
			right=midright;
		}
		else
		{
			left=midleft;
		}
		
		if(midright - midleft < 1e-15) break;
	}
	
	printf("%.11lf",GetL(left));
	
	return 0;
}
