#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
bool flag[10][10];
int n,m,t;
int sx,sy,fx,fy;
int res=0;
void dfs(int x,int y)
{
	if(x==fx&&y==fy)
	{
		res++;
		return ;
	}
	
	for(int i=0;i<4;i++)
	{
		int a=x+dx[i];int b=y+dy[i];
		if(a<1||b<1||a>n||b>m)continue;
		if(!flag[a][b])continue;
		else{
			flag[a][b]=false;
			dfs(a,b);
			flag[a][b]=true;
		}
	}
	
}
int main()
{
	cin >> n >> m >> t;
	cin >> sx >> sy >> fx >> fy;
	memset(flag,true,sizeof(flag));
	for(int i=0;i<t;i++)
	{
		int b_fx,b_fy;
		cin >>b_fx >>b_fy;
		flag[b_fx][b_fy]=false;
	}
	flag[sx][sy]=false;
	dfs(sx,sy);
	cout <<  res;
	return 0;
	
}
