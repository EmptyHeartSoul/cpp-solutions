#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		string t;
		cin >> s;
		int l=0,r=s.size()-1;
		while(l<=r)
		{
			if(s[l]<s[r])
			{
				t.push_back(s[l++]);
			}
			else if(s[l]>s[r])
			{
				t.push_back(s[r--]);
			}
			else
			{
				if(l==r)
				{
					t.push_back(s[l]);
					break;
				}
				char g=s[l];
				int posL = l+1;
				while(posL <=r && s[posL]==g)posL++;
				int posR =r-1;
				while(posR >= l&& s[posR]==g)posR--;
				if(posL > r || posR < l)
				{
					int len = r-l+1;
					int take =len/2+1;
					t.append(take,g);
					break;
				}
				
				char leftInner = s[posL];
				char rightInner = s[posR];
				
				bool leftSmaller = (leftInner < g );
				bool rightSmaller = (rightInner < g );
				
				if(leftSmaller && rightSmaller)
				{
					t.push_back(g);
					l++,r--;
				}
				else if(leftSmaller && !rightSmaller)
				{
					t.push_back(g);
					l++;
				}
				else if(!leftSmaller && rightSmaller)
				{
					t.push_back(g);
					r--;
				}
				else
				{
					t.push_back(g);
					t.push_back(g);
					l++;
					r--;
				}
			}
		}
		cout << t << endl;
	}
}
