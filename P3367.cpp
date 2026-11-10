#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> arr(200005);
int dfs(int x)
{
	if(arr[x]==x)return x;
	return arr[x]=dfs(arr[x]);
}
void merge(int x,int y)
{
	int a=dfs(x);
	int b=dfs(y);
	if(a!=b)arr[a]=b;
}
int main()
{
	cin >> n>> m;
	for(int i=1;i<=n;i++)arr[i]=i;
	for(int i=0;i<m;i++)
	{
		int z,x,y;
		cin >> z >> x >> y;
		if(z==1)
		{
			merge(x,y);
		}
		if(z==2)
		{
			int num1=dfs(x);
			int num2=dfs(y);
			if(num1==num2)
			{
				cout << "Y" <<endl;
			}
			else cout << "N" <<endl;
		}
	}
}
