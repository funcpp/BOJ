#include <stdio.h>
int n,m;
int line[105][105];
int kb[105][105];
int chk[105];
long long int ans[105];

void dfs(int idx, int cur, int goal, int cnt)
{
	if(cur==goal)
	{
		if(kb[idx][goal] > cnt || kb[idx][goal]==0)
		{
			kb[idx][goal]=cnt;
			kb[goal][idx]=cnt;
		}
		return;
	}
	
	for(int i=0; i<n; i++)
	{
		if(idx==i || chk[i]) continue;
		
		if(line[cur][i])
		{
			chk[i]=1;
			dfs(idx,i,goal,cnt+1);
			chk[i]=0;
		}
	}
	return;
}

void save(int idx)
{
	for(int i=0; i<n; i++)
	{
		if(idx==i || kb[idx][i]!=0) continue;
		
		chk[idx]=1;
		dfs(idx,idx,i,0);
		chk[idx]=0;
	}
	return;
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		line[a-1][b-1]=1;
		line[b-1][a-1]=1;
	}
	
	long long int min=987654321;
	int aIdx=0;
	for(int i=0; i<n; i++)
	{
		save(i);
		long long int sum =0;
		for(int j=0; j<n; j++)
		{
			if(i==j) continue;
			sum += kb[i][j];
		}
		
		if(sum < min)
		{
			min=sum;
			aIdx=i+1;
		}
	}
	
	/*
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%2d ",kb[i][j]);
		}
		printf("\n");
	}
	*/
	
	printf("%d",aIdx);
	
	return 0;
}
