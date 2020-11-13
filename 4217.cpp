#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <string>
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;
int H,W;
int arr[1000][1000];
map<pair<int,int>, int> chk;
int chk2[1000][1000];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
#define pii pair<int,int>

vector<int> hex2bin(char c)
{
    int dec=0;
    
    if(0<= c-'0' && c-'0' <= 9)
    {
        dec = c-'0';
    }
    else
    {
        dec = 10 + c-'a';
    }
    
    vector<int> ret;
        
    while(dec)
    {
        ret.push_back(dec%2);
        dec/=2;
    }

    while(ret.size()!=4) ret.push_back(0);
    
    reverse(ret.begin(),ret.end());
    return ret;
}

void dfs(int x, int y, int num)
{
    //chk[{x,y}]=num;
    chk2[x][y]=num;
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx<0 || nx>H+1 || ny<0 || ny>W+1) continue;
        
        //if(!chk.count({nx,ny}) && arr[nx][ny]==arr[x][y])
        if(!chk2[nx][ny] && arr[nx][ny]==arr[x][y])
        {
            dfs(nx,ny,num);    
        }
    }
}

int main()
{    
    //char c;
    //scanf("%c",&c);
    //printf("%d %d\n",c-'0',c-'a');
    //vector<int> a =hex2bin(c);
    //for(int i=0; i<a.size(); i++) printf("%d",a[i]);
    int T = 0;
    while(true)
	{
		memset(arr, 0, sizeof(arr));
		memset(chk2, 0, sizeof(chk2));
		chk.clear();
	    scanf("%d %d",&H,&W);
	    if(!H && !W) return 0;
	    for(int i=0; i<H; i++)
	    {
	        string s;
	        cin >> s;
	        for(int j=0; j<W; j++)
	        {
	            vector<int> v = hex2bin(s.substr(j,1).c_str()[0]);
	            for(int k=0; k<4; k++) arr[i+1][j*4+k+1]=v[k];
	        }
	    }
	    W*=4;
		
	    int num=1;
	    for(int i=1; i<=H; i++)
	    {
	        for(int j=1; j<=W; j++)
	        {
	            if(!chk2[i][j])
	            {
	                //printf("dfs %d %d\n",i,j);
	                dfs(i,j,num++);
	            }
	        }
	    }
	    /*
	    printf("-\n");
	    
	    for(int i=0; i<=H; i++)
	    {
	        for(int j=0; j<=W; j++)
	        {
	            printf("%d",chk2[i][j]);
	        }
	        printf("\n");
	    }*/
	    
	    
	    vector<int> v[num+1];
	    
	    for(int i=1; i<=H; i++)
	    {
	        for(int j=1; j<=W; j++)
	        {
	            if(arr[i][j])
	            {
	                for(int k=0; k<4; k++)
	                {
	                    int nx = i + dx[k];
	                    int ny = j + dy[k];
	                    
	                    if(nx<0 || nx>H+1 || ny<0 || ny>W+1) continue;
	                    
	                    if(arr[nx][ny] == 0)
	                    {
	                        v[chk2[i][j]].push_back(chk2[nx][ny]);
	                    }
	                }
	            }
	        }
	    }
	    
	    
	    vector<string> ans;
	    
	    for(int i=0; i<num+1; i++)
	    {
	        sort(v[i].begin(),v[i].end());
	        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
	        if(!v[i].size()) continue;
	        
	        int cnt = v[i].size()-1;
	        switch(cnt)
	        {
	            case 1:
	                ans.push_back("A");//printf("A");
	                break;
	            case 3:
	                ans.push_back("J");//printf("J");
	                break;
	            case 5:
	                ans.push_back("D");//printf("D");
	                break;    
	            case 4:
	                ans.push_back("S");//printf("S");
	                break;
	            case 0:
	                ans.push_back("W");//printf("W");
	                break;
	            case 2:
	                ans.push_back("K");//printf("K");
	                break;            
	        }
	    }
	    
	    sort(ans.begin(),ans.end());
	    
	    printf("Case %d: ",++T);
	    
	    for(int i=0; i<ans.size(); i++)
	    {
	        printf("%c",ans[i].c_str()[0]);
	    }
	    printf("\n");
	}
    return 0;
}
