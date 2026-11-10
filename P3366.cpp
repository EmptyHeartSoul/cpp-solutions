#include <bits/stdc++.h>
using namespace std;
struct Tree
{
	int u,v,w;
};
Tree arr [200005];

int arr2[5050];
bool cmp(Tree a,Tree b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(arr2[x]==x)return x;
	return arr2[x]=find(arr2[x]);
}
void merge(int x,int y)
{
	int a=find(x);
	int b=find(y);
	if(a!=b)arr2[a]=b;
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)arr2[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin >> arr[i].u >>arr[i].v>>arr[i].w;
	}
	sort(arr,arr+m,cmp);
	int cnt =0;
	int ans =0;
	for(int i=1;i<=m;i++)
	{
		int u= arr[i].u;
		int v=arr[i].v;
		int w=arr[i].w;
		if(find(u)!=find(v))
		{
			merge(u,v);
			ans+=w;
			cnt++;
			if(cnt==n-1)break;
			
		}
	}
	if(cnt==n-1)
	{
		cout << ans;
	} 
	else{
		cout << "orz";
	}
	
}
