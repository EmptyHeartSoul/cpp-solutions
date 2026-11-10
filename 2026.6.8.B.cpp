#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool if_not(long long x) {
	string s = to_string(x);
	return s == string(s.rbegin(), s.rend());
}

int main() {
	vector<long long> arr;
	for (int len = 1; len <= 18; len++) {
		int half = (len + 1) / 2;
		long long start = 1;
		for (int i = 1; i < half; i++) start *= 10;
		long long end = start * 10;
		for (long long left = start; left < end; left++) {
			string s = to_string(left);
			string t = s;
			reverse(t.begin(), t.end());
			string full;
			if (len % 2 == 0) full = s + t;
			else full = s + t.substr(1);
			long long num = stoll(full);
			if (num > 1000000000000000000LL) break;
			arr.push_back(num);
		}
	}
	arr.push_back(0); 
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		long long n;
		cin >> n;
		int flag = 0;
		auto it = upper_bound(arr.begin(), arr.end(), n);
		if (it != arr.begin()) {
			int index = (it - arr.begin()) - 1;
			while (index >= 0) {
				long long value = arr[index];
				long long b = n - value;
				if (b % 12 == 0) {
					cout << value << ' ' << b << endl;
					flag = 1;
					break;
				}
				index--;
			}
		}
		if (!flag) cout << -1 << endl;
	}
	return 0;
}
