#include <bits/stdc++.h>
using namespace std;
const int INF=2147483647;
int n,m;
long long  digt[100005];
bool visted[100005];
vector<pair<int ,int>>G[1000005];
vector<pair<int,int>>G_rew[1000005];
void dj(int start)
{
	for(int i=1;i<=n;i++)digt[i]=INF;
	digt[start]=0;
	priority_queue<pair<long long  ,int>,vector<pair<long long ,int>>,greater<pair<long long ,int>>>pq;
	pq.push({0,start});
	while(!pq.empty())
	{
		long long  d=pq.top().first;//目前能选的最短路
		int u=pq.top().second;//此时选出的最短节点
		pq.pop();
		
		if(visted[u])continue;
		visted[u]=true;
		
		for(auto edge:G[u])
		{
			int v=edge.first;
			int w=edge.second;
			if(d+w<digt[v])
			{
				digt[v]=d+w;
				pq.push({digt[v],v});
			}
		}
		
		
	}	
}
void djs(int start)
{
	for(int i=1;i<=n;i++)digt[i]=INF;
	digt[start]=0;
	priority_queue<pair<long long  ,int>,vector<pair<long long ,int>>,greater<pair<long long ,int>>>pq;
	pq.push({0,start});
	while(!pq.empty())
	{
		long long  d=pq.top().first;//目前能选的最短路
		int u=pq.top().second;//此时选出的最短节点
		pq.pop();
		
		if(visted[u])continue;
		visted[u]=true;
		
		for(auto edge:G_rew[u])
		{
			int v=edge.first;
			int w=edge.second;
			if(d+w<digt[v])
			{
				digt[v]=d+w;
				pq.push({digt[v],v});
			}
		}
		
		
	}	
}


int main()
{
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w});
		G_rew[v].push_back({u,w});
	}
	dj(1);
	long long  ans=0;
	long long  digt_out[100005];
	for(int i=1;i<=n;i++)
	{
		digt_out[i]=digt[i];
	}
	memset(visted,0,sizeof(visted));
	djs(1);
	for(int i=1;i<=n;i++)
	{
		ans+=digt_out[i]+digt[i];
	}
	cout << ans <<endl;
	
}
