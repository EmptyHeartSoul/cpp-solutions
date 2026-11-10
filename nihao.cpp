#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	if(n<m)
	{
		cout << "NO" << endl;
		return 0;
	}
   if (m == 0) {
		cout << "YES" << endl;
	    for (int i = 0; i < n; i++) 
		{
		   string s(n, '0');
		   s[i] = '1';
		   cout << s << '\n';
	    }
	    return 0;
   }
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) 
	{
		string s(n, '0');
		if (i < m) 
		{
			for (int j = i+1 ; j < m; j++) 
			{
				s[j] = '1';
			}
		}
		cout << s << '\n';
	}
	return 0;
}
