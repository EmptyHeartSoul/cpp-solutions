#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string s;
		string t;
		cin >> s;
		int l=0;
		int r=s.size()-1;
		while(l<=r)
		{
			if(s[l]!=s[r])
			{
				if(s[l]>s[r])
				{
					t+=s[r];
					r--;
				}	
				else
				{
					t+=s[l];
					l++;
				}
			}
			else
			{
				if(l<=r)
				{
					if(s[l]>s[l+1]||s[r]>s[r-1])
					{
						t+=s[l];
						l++;
						r--;
					}
					else if(s[l]==s[l-1]&&s[r]==s[r-1])
					{
						t+=s[l];
						l++;
						r--;
					}
					else
					{
						
						t+=s[l];
						l++;
					}
					
				}
				else
				{
					t+=s[l];
				}
			}
			
		}
		cout << t << endl;
	}
	
	
}
