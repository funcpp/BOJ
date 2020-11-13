#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <memory.h>

using namespace std;

int mstick[10]={6,2,5,5,4,5,6,3,7,6};
int K;

int cache[105][105];

bool isGoodLen(int len, int cnt)
{
	if(!len) return !cnt;
	if(cnt <= 0) return false;
	
	int& ret = cache[len][cnt];
	
	if(ret != -1) return ret;
	
	ret=0;
	
	for(int i=0; i<10; i++)
	{
		ret |= isGoodLen(len-1,cnt-mstick[i]);
	}
	
	return ret;
}

string min_num;
void track(int len, int cnt, bool isInit)
{
	if(!isInit && isGoodLen(len-1,cnt-mstick[0]))
	{
		min_num+="0";
		track(len-1,cnt-mstick[0], false);
		return;
	}
	
	for(int i=1; i<10; i++)
	{
		if(isGoodLen(len-1,cnt-mstick[i]))
		{
			min_num+=(char)(0x30+i);
			track(len-1,cnt-mstick[i],false);
			break;
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	memset(cache,-1,sizeof(cache));
	while(T--)
	{
		scanf("%d",&K);
		
		string max_num="";
		int tmp=K;
		if(tmp&1)
		{
			tmp-=3;
			max_num+="7";
		}
		for(int i=0; i<tmp/2; i++) max_num+="1";
		
		min_num="";
		int min_len=0;
		for(int i=1; i<=100; i++)
		{
			if(isGoodLen(i,K))
			{
				min_len=i;
				break;
			}
		}
		
		track(min_len,K,true);
		
		cout << min_num << " " << max_num << endl;
	}
	
	return 0;
}
