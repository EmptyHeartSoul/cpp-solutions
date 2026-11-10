#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a=0;
	while(n--)
	{
		int sum;
		cin >> sum;
		a=a^sum;
	}
	cout << a;
	
}
