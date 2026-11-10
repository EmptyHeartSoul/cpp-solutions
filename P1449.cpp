#include <bits/stdc++.h>
using namespace std;
int main()
{
	stack<int> st;
	char c;
	int num=0;
	while(cin >> c)
	{
		if(c=='@')break;
		if(c>='0'&&c <='9')
		{
			num=num*10+(c-'0');
		}
		else if(c=='.')
		{
			st.push(num);
			num=0;
			continue;
		}
		else
		{
			int b=st.top();st.pop();
			int a=st.top();st.pop();
			
			if(c=='/')st.push(a/b);
			if(c=='-')st.push(a-b);
			if(c=='+')st.push(a+b);
			if(c=='*')st.push(a*b);
		}
	}
	cout << st.top();
	
	
	
}
