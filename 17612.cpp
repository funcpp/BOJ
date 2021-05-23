#include <bits/stdc++.h>
using namespace std;


/*

마치는시간 작을수록 pop
계산대번호<<<<<<<<<빼는것부터push
번호가높을수록 빠르게 pop

{-마치는시간, 계산대번호, 유저id}

*/

int N,K;

struct st
{
	int id, t, i;
};

int main()
{
	scanf("%d %d", &N, &K);
	
	priority_queue<st, vector<st>, function<bool(st, st)>> pq([](const st& lhs, const st& rhs)
	{
		if(lhs.t == rhs.t) return lhs.i > rhs.i;
		return lhs.t > rhs.t;
	}); // {{-fin_t, idx}, id}
	
	vector<st> v;
	for(int i=0,id,w; i<N; i++)
	{
		scanf("%d %d",&id, &w);
		
		if(i<K)
		{
			//printf("[IN]%d %d %d\n",id,w,i);
			pq.push({id, w, i});
			continue;
		}
		
		//printf("[IN]%d %d %d\n",id,w+pq.top().t,pq.top().i);
		pq.push({id, w + pq.top().t, pq.top().i});
		//printf("[OUT]%d %d %d\n",pq.top().id,pq.top().t,pq.top().i);
		v.push_back(pq.top());
		pq.pop();
	}
	
	while(pq.size()){
		v.push_back(pq.top());
		pq.pop();
	}
	
	sort(v.begin(), v.end(), [](const st& lhs, const st& rhs)
	{
		if(lhs.t == rhs.t) return lhs.i > rhs.i;
		return lhs.t < rhs.t;
	});
	
	unsigned long long int ans = 0;
	long long int cnt = 1;
	for(st s : v)
	{
		ans += s.id * (cnt++);
	}
	
	printf("%llu",ans);
	
	return 0;
}
