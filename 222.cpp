#include <bits/stdc++.h>
using namespace std;
struct  Student{
	int id;
	int chinese;
	int total;
};
bool cmp(Student a,Student b)
{
	if(a.total!=b.total)
		return a.total>b.total;
	if(a.chinese !=b.chinese)
		return a.chinese>b.chinese;
	return a.id<b.id;
}
int main()
{
	int n;
	cin >> n;
	vector<Student>stu(n);
	for(int i=0;i<n;i++)
	{
		int c,m,e;
		cin >> c >> m >> e;
		stu[i].id=i+1;
		stu[i].chinese=c;
		stu[i].total=(c+m+e);
	}
	sort(stu.begin(),stu.end(),cmp);
	int min_num=min(n,5);
	for(int i=0;i<min_num;i++)
	{
		cout <<stu[i].id<< " "<< stu[i].total<<endl; 
	}
	return 0;
}
