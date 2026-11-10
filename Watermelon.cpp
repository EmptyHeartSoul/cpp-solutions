#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if(n%2==0)
	{
		int flag=n/2;
		if(flag%2==0)cout << "YES" <<endl;
		else cout << "NO" << endl;
	}
	else cout << "NO" << endl;
	
}
