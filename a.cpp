#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int sum;
		cin >> sum;
		int min=0;

		int a,b,c;
		cin >> a >> b >> c;
		min=a<b?(a<c?a:c):(b<c?b:c);
		cout << (sum-min) <<endl; 
	}
}
