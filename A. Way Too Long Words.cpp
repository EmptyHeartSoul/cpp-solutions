#include <iostream>
using namespace std;
	bool check1(int x,int num)
	{
		if(num<x)return true;
		else return false;
	}
	bool check2(int x,int num)
	{
		if(num<=x)return true;
		else return false;
	}
	int find(int arr[],int len,int x,int flag)
	{
		int l=-1;
		int r=len;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(flag)
			{
				if(check1(arr[mid],x))l=mid;
				else r=mid;
			}
			else
			{
				if(check2(arr[mid],x))l=mid;
				r=mid;
			}
		}
		
		
		
		
	}
	int b_s(int arr[],int len,int x)
	{
		int l=-1;
		int r=len;
		while(l+1<r)
		{
			int mid=(l+r)>>1;
			if(arr[mid]>=x)l=mid;
			else r=mid;
		}
		return l;
	}
	int main()
	{
		int n,k;
		cin >> n >> k;
		int arr[51];
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		if(arr[0]==0)cout << '0';
		int num=b_s(arr,n,arr[k-1]);
		cout << num+1 ;
		
	}	
	int main()
	{
		int n,m;
		cin >> n >> m;
		int sum=n*m;
		cout << sum/2;
		
		
	}
	int main()
	{
		int n;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			int num=3;
			int  a,b,c;
			cin >> a ;
			cin >> b ;
			cin >> c;
			if(a==b)
			{
				if(a==c)
				{
					num-=2;
					
				}
				else
				{
					num--;
				}
			}
			else
			{
				if(a==c)
				{
					num--;
				}
				else
				{
					if(b==c)
					{
						num--;
					}
				}
				
			}
			cout << num << endl;
			
		}
	}
int main()
{
	int n,m;
	cin >> n >> m;
	
}
