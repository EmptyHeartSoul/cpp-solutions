#include <bits/stdc++.h>
using namespace std;
int n,m,s,t;
const int INE=99999999;

int digt[1000005];
bool visited[1000005];

vector<pair<int ,int>>G[1000005];
void dj(int start)
{
	for(int i=1;i<=n;i++)digt[i]=INE;
	digt[start]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,start});
	while(!pq.empty())
	{
		int q=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(visited[u])continue;
		visited[u]=true;
		for(auto edge: G[u])
		{
			int d=edge.first;
			int w=edge.second;
			if(q+w<digt[d])
			{
				digt[d]=w+q;
				pq.push({digt[d],d});
			}
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>n >> m >> s >> t;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	dj(s);
	cout << digt[t];
	
	
	
	
	
}
