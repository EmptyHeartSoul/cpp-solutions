#include <bits/stdc++.h>
using namespace std;
char map_1[105][105];
bool visted[105][105];
int n,m;
int res=0;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,1,-1,-1,0,1};
void dfs(int x,int y)
{
	
	for(int i=0;i<8;i++)
	{
		
		int a=x+dx[i];int b=y+dy[i];
		if(a<0||b<0||a>=n||b>=m)continue;
		if(visted[a][b])continue;
		if(map_1[a][b]!='W')continue;
		visted[a][b]=true;
		dfs(a,b);
	}
	
}
int main()
{
	
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> map_1[i][j];
		}
		
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map_1[i][j]=='W'&&!visted[i][j])
			{
				visted[i][j]=true;
				res++;
				dfs(i,j);
			}
		}	
	}
	cout << res;
}
