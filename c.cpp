#include <iostream>
#include <string>

using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool flag=0;
		for(int j=0;j<(int)s.size()-1;j++)
		{
			if(s[j]=='1'&&s[j+1]=='0')
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			cout << '0' << endl;
			continue;
		}
		if(s[0]=='1')
		{
			
			
			
			
			
		}
		
		
		
		
	}
}
