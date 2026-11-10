#include<bits/stdc++.h>
using namespace std;

int n,m,b;
const long long INF=1e18;
const int MAXN=10005;
int cost[MAXN];
vector<pair<int ,long long>> G[MAXN];
long long dist[MAXN];
bool visited[MAXN];

bool check(int limit_cost)
{
	if(cost[1]>limit_cost||cost[n]>limit_cost)return 0;
	for(int i=1;i<=n;i++)
	{
		dist[i]=INF;
		visited[i]=0;
	}
	dist[1]=0;
	priority_queue<pair<long long ,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	pq.push({0,1});
	while(!pq.empty())
	{
		long long d=pq.top().first;
		long long u=pq.top().second;
		pq.pop();
		if(visited[u])continue;
		visited[u]=true;
		for(auto edge:G[u])
		{
			long long v=edge.first;
			long long w=edge.second;
			if(cost[v]<=limit_cost&&d+w<dist[v])
			{
				dist[v]=d+w;
				pq.push({dist[v],v});
			}
		}
	}
	return dist[n]<=b;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> b;
	int max_cost=0;
	for(int i=1;i<=n;i++)
	{
		cin >> cost[i];
		max_cost=max(max_cost,cost[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	
	if(!check(max_cost))
	{
		cout << "AFK\n"	;
		return 0;
	}
	
	int l=1;
	int r=max_cost;
	int ans;
	while(l<=r)
	{
		int mid= (l+r)/2;//另一种写法l+((r-l)>>1)
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout << ans;
	
	
	
}
