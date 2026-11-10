#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int num;
	cin >> num;
	for(int k=0;k<num;k++)
	{	
		int n;
		cin >> n;
		vector <int>arr;
		for(int i=0;i<n;i++)
		{
			int x;
			cin >>x;
			arr.push_back(x);
		}
		sort(arr.rbegin(),arr.rend());
		int sum=arr[0];
		for(int i=0;i<n;i++)
		{
			if(i<n-1)
			{
				int flag=0;
				int choose_num=arr[0];
				int cur_num;
				cur_num=choose_num^arr[i+1];
				while(cur_num)
				{
					if(cur_num &1)
					{
						flag++;
					}
					cur_num=cur_num >> 1;
				}
				if(!flag & 1)
				{
					sum+=arr[i+1];
					choose_num=arr[i+1];
				}
				
			}
			
		}
		cout << sum << endl;
	}
	
}
