#include <bits/stdc++.h>
using namespace std;
int n,a,b;
int k[205];
int dist[205];
int bfs()
{
	queue<int> q;
	q.push(a);
	dist[a]=0;
	while(!q.empty())
	{
		int head=q.front();
		q.pop();
		if(head==b)return dist[head];
		int next_top=head+k[head];
		int next_down=head-k[head];
		if(next_top<=n&&dist[next_top]==-1)
		{
			dist[next_top]=dist[head]+1;
			q.push(next_top);
		}
		if(next_down>0&&dist[next_down]==-1)
		{
			dist[next_down]=dist[head]+1;
			q.push(next_down);
		}
	}
	return -1;
}
int main()
{
	cin >> n >>a >> b;
	for(int i=1;i<=n;i++)
	{
		cin >> k[i];
	}
	memset(dist,-1,sizeof(dist));
	int num=bfs();
	if(num==-1)
	{
		cout << "-1";
	}
	else
		cout << num;
	
	
}
