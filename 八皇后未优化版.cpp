#include <iostream>
using namespace std;
int n,ans=0;
int pos[15];
bool col[15];
bool ld[30],rd[30];
void dfs(int row)
{
	if(row==n)
	{
		ans++;
		if(ans<=3)
		{
			for(int i=0;i<n;i++)
			{
				cout << pos[i]+1<<' ';
			}
			cout << endl;
		}
		return ;
	}
	
	for(int c=0;c<n;c++)
	{
		if(!col[c]&&!ld[row-c+n]&&!rd[c+row])
		{
			pos[row]=c;
			col[c]=true;
			ld[row-c+n]=true;
			rd[c+row]=true;
			dfs(row+1);
			col[c]=false;
			ld[row-c+n]=false;
			rd[c+row]=false;
		}
	}
	
	
}
int main()
{
	cin >> n;
	dfs(0);
	cout<< ans<<endl;
	return 0;
	
}
