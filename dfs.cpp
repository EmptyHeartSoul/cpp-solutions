#include <iostream>
#include <iomanip>
using namespace std;
int n;
int a[10];
bool flag[10];
void dfs(int step)
{
	if(step==n)
	{
		for(int i=0;i<n;i++)
		{
			cout <<setw(5)<< a[i] ;
		}
		cout << endl ;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			flag[i]=true;
			a[step]=i;
			dfs(step+1);
			flag[i]=false;
		}
	}
}
int main()
{
	cin >>n;
	dfs(0);
	return 0;
}
