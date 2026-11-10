#include <bits/stdc++.h>
using namespace std;
vector<int> G[100005];
bool visited[100005];

void dfs(int u)
{
	cout << u<< " ";
	visited[u]=true;
	for(int v:G[u])
	{
	 
		if(!visited[v])
		{
			dfs(v);
		}	
		
	}
	
}
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start]=true;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		cout << u <<" ";
		for(int v : G[u])
		{
			if(!visited[v])
			{
				q.push(v);
				visited[v]=true;
			}
		}
	}
}
int main ()
{	
	int n,m;
	cin >> n >>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin >> u >>v;
		G[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
	{
		sort(G[i].begin(),G[i].end());
	}
	dfs(1);
	cout << "\n";
	memset(visited,false,sizeof(visited));
	bfs(1);
	cout << "\n";
	return 0;
	
	
	
}
