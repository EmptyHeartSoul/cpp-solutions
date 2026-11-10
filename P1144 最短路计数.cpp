#include <bits/stdc++.h>
using namespace std;

int n,m;
const int MOD=100003 ;
vector <int> G[1000005];
int dist[1000005];
int cnt[1000005];
void djs(int start)
{
	for(int i=1;i<=n;i++)
	{
		dist[i]=-1;
		cnt[i]=0;
	}
	dist[start]=0;
	cnt[start]=1;
	queue<int> q;
	q.push(start);
	while(!q.empty())
	{
		int h=q.front();
		q.pop();
		for(auto v:G[h])
		{
			if(dist[v]==-1)
			{
				dist[v]=dist[h]+1;
				cnt[v]=cnt[h];
				q.push(v);
			}
			else if(dist[v]==dist[h]+1)
			{
				cnt[v]=(cnt[v]+cnt[h])%MOD;
			}
		}
		
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	djs(1);
	for(int i=1;i<=n;i++)
	{
		cout << cnt[i] <<endl;	
	}
}
