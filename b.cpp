#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		long long  a,b,c;
		cin >> a >> b >> c;
		if(abs(a-b)>a-b+c)
		{
			cout<<abs(a-b)<<endl;
		}
		else
		{
			cout<<(a-b+c)<<endl;
		}
	}
}
