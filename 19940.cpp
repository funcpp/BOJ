#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct st
{
	//ah at mt ao mo 
	int arr[5]={0,};
	/*
	bool const operator>(const struct st& s){
		for(int i=0;i<5;i++){
			if(s.arr[i]==this->arr[i]) continue;
			else if(s.arr[i]>this->arr[i]) return true;
			else return false;
		}
		return false;
	}
	*/
	int  getCnt()
	{
		return arr[0]+arr[1]+arr[2]+arr[3]+arr[4];
		//int ret=0;for(int i=0;i<5;i++)ret+=arr[i];return ret;
	}
	
	void  pr()
	{/*
		for(int i=0;i<5;i++){
			printf("%d ",arr[i]);
		}*/
		printf("%d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4]);
	}
};

void  addb(int a, st& s)
{
	if(a>0){
		int over = (a / 10 + 1) + ((a / 10 + 1) * 10 - a);
		int under = (a/10) + (a%10);
		
		if(over >= under){
			s.arr[1] = a/10;
			s.arr[3] = a%10;
		}
		else{
			s.arr[1] = a/10+1;
			s.arr[4] = (a / 10 + 1) * 10 - a;
		}
	}
	else{
		a*=-1;
		
		int over = (a / 10 + 1) + ((a / 10 + 1) * 10 - a);
		int under = (a/10) + (a%10);
		
		if(over >= under){
			s.arr[2] = a/10;
			s.arr[4] = a%10;
		}
		else{
			s.arr[2] = a/10+1;
			s.arr[3] = (a / 10 + 1) * 10 - a;
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--){
		int a; scanf("%d",&a);
		if(a%60==0) {
			printf("%d 0 0 0 0\n",a/60); continue;
		}
		
		st over;
		over.arr[0]=(a/60)+1;
		
		st under;
		under.arr[0] = a/60;
		
		addb(a-over.arr[0]*60, over);
		addb(a-under.arr[0]*60, under);
		
		if(over.getCnt() >= under.getCnt()){
			under.pr();
		}
		else {
			over.pr();
		}
	}
	return 0;
}
