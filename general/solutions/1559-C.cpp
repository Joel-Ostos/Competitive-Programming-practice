#include <bits/stdc++.h>
using namespace std;

#define int long long

void print_(int beg, int end) 
{
	for (int i = beg; i <= end; i++) cout << i << " "; 
}

bool bs_(vector<int>& v, int t) 
{
	if (v.size()==0) return false;
	int l = 0, r = v.size()-1;
	while (l<=r) {
		int mid = l+(r-l)/2;
		if (v[mid]==t) return true; 
		if (v[mid]>t) r = mid-1;
		else l = mid+1;
	}
	return false;
}

void solve()
{
	int n; cin >> n;
	vector<int> in, out;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		if (!tmp) {
			in.push_back(i);
			continue;
		}
		out.push_back(i);
	}
	sort(in.begin(), in.end()); 
	sort(out.begin(), out.end());
	if (bs_(in, n)) {
		print_(1, n+1);
		cout << '\n';
		return;
	}
	if (bs_(out, 1)) {
		cout << n+1 << " ";
		print_(1, n);
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if(bs_(in, i) && bs_(out, i+1)) {
			print_(1, i);
			cout << n+1 << " " ;
			print_(i+1, n);
			cout << '\n';
			return;
		}
	}
	cout << "-1\n";
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) solve();
}
