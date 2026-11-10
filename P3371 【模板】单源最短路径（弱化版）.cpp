#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,s;
long long  dist[100005];
bool visted[100005];


vector<pair<int ,int>>G[500005];
void dj(int start)
{
	for(int i=1;i<=n;i++)dist[i]=INF;
	dist[start]=0;
	priority_queue<pair<long long ,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	pq.push({0,start});
	while(!pq.empty())
	{
		long long d=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		
		if(visted[u])continue;
		visted[u]=1;
		
		for(auto edge:G[u])
		{
			int v=edge.first;
			int w=edge.second;
			if(d+w<dist[v])
			{
				dist[v]=d+w;
				pq.push({dist[v],v});
			}
		}
		
	}
}
int main()
{
	cin >> n>> m>>s;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin >> u>>v>>w;
		G[u].push_back({v,w});
	}
	dj(s);
	for(int i=1;i<=n;i++)
	{
		
		cout << dist[i]<< " ";
	}
	
}
