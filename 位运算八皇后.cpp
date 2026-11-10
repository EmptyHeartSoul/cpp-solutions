#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,ans=0;
int pos[15];
vector<string>arr(n);
void dfs(int row,int col,int ld,int rd)
{
	if(row==n)
	{
		return ;
	}
	int yes=(~(col|ld|rd))&((1<<n)-1);
	while(yes)
	{
		int p=-yes&yes;
		yes -=p;
		pos[row]=__builtin_ctz(p);
		dfs(row+1,col|p,(ld|p)<< 1,(rd|p) >>1);
	}
}
int main()
{
	cin >> n;
	
	dfs(0,0,0,0);
	cout << ans;
  
}
