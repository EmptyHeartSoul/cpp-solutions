#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
const int MAX=1e5+5;
int N,R;
long long dist[MAX];
bool visited[MAX];
vector <pair<int,long long >>G[MAX];
void dj(int start)
{
	for(int i=1;i<=N;i++)dist[i]=INF;
	dist[start]=0;
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq ;
	pq.push({0,start});
	while(!pq.empty())
	{
		long long  d=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(visited[u])continue;
		visited[u]=1;
		for(auto edge: G[u] )
		{
			int v=edge.first;
			long long w=edge.second;
			if(d+w<dist[v])
			{
				dist[v]=d+w;
				pq.push({dist[v],v});
			}
		}
		
	}
}
struct tu
{
	int u,v,w;
};
tu arr[MAX];



int main()
{
	cin >> N >> R;
	for(int i=1;i<=R;i++)
	{
		int A,B,D;
		cin >> A >> B >> D;
		G[A].push_back({B,D});
		G[B].push_back({A,D});
		arr[i].u=A;
		arr[i].v=B;
		arr[i].w=D;
	}
	dj(1);
	long long distN[MAX];
	for(int i=1;i<=N;i++)
	{
		distN[i]=dist[i];
	}
	for(int i=1;i<=N;i++)
	{
		visited[i]=0;
	}
	dj(N);
	long long shortd=distN[N];
	long long min=INF;
	for(int i=1;i<=R;i++)
	{
		long long sum1=dist[arr[i].u]+arr[i].w+distN[arr[i].v];
		long long sum2=dist[arr[i].v]+arr[i].w+distN[arr[i].u];
		
		if(sum1>shortd&&sum1<min)
		{
			min=sum1;	
		}
		if(sum2>shortd&&sum2<min)
		{
			min=sum2;
		}
		
	}
	cout <<  min;
	
	
	
}
