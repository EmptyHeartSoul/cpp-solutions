#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
int dx[8]={1,2,1,2,-1,-2,-1,-2};
int dy[8]={2,1,-2,-1,-2,-1,2,1};
int dist[405][405];
void bfs()
{
	queue<pair<int ,int>> q;
	q.push({x,y});
	dist[x][y]=0;
	while(!q.empty())
	{
		int head_x=q.front().first;
		int head_y=q.front().second;
		q.pop();
		for(int i=0;i<8;i++)
		{
			int px=head_x+dx[i];
			int py=head_y+dy[i];
			if(px<1||px>n||py<1||py>m)continue;
			if(dist[px][py]==-1)
			{
				dist[px][py]=dist[head_x][head_y]+1;
				q.push({px,py});
			}
		}
	}
	return ;
}




int main()
{
	cin >> n >> m >> x >> y;
	memset(dist,-1,sizeof(dist));
	bfs();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout << dist[i][j]<<" "; 	
		}
		cout << endl;
	}
}
