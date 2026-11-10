#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int n = s.size();
		
		vector<int> leftarr(n, -1), rightarr(n, n);
		for (int i = 0; i < n; ) {
			char cur = s[i];
			int j = i;
			while (j < n && s[j] == cur) ++j;
			for (int k = i; k < j; ++k)
				leftarr[k] = (i > 0 ? i - 1 : -1);
			i = j;
		}
		for (int i = n - 1; i >= 0; ) {
			char cur = s[i];
			int j = i;
			while (j >= 0 && s[j] == cur) --j;
			for (int k = i; k > j; --k)
				rightarr[k] = (i < n - 1 ? i + 1 : n);
			i = j;
		}
		
		string ans;
		int l = 0, r = n - 1;
		while (l <= r) {
			if (s[l] < s[r]) {
				ans.push_back(s[l++]);
			} else if (s[l] > s[r]) {
				ans.push_back(s[r--]);
			} else {
				if (l == r) {
					ans.push_back(s[l]);
					break;
				}
				char g = s[l];
				if (rightarr[l] > r || leftarr[r] < l) {
					int len = r - l + 1;
					int take = len / 2 + 1;
					ans.append(take, g);
					break;
				}
				
				int posL = rightarr[l];
				int posR = leftarr[r];
				char leftInner = s[posL];
				char rightInner = s[posR];
				bool leftSmaller = (leftInner < g);
				bool rightSmaller = (rightInner < g);
				
				if (leftSmaller && rightSmaller) {
					ans.push_back(g);
					++l; --r;
				} else if (leftSmaller && !rightSmaller) {
					ans.push_back(g);
					++l;
				} else if (!leftSmaller && rightSmaller) {
					ans.push_back(g);
					--r;
				} else {
					ans.push_back(g);
					ans.push_back(g);
					++l; --r;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
