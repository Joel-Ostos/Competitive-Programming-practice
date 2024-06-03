#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

void solve() 
{
	int n, k; cin >> n >> k;
	vector<int> v(n);
	vector<pair<int, int>> r;
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i <= n-k; i++) {
		int sum = v[i];
		for (int j = 1; j < k; j++) {
			sum += v[i+j]*(j+1);
		}
		pair<int, int> p; 
		p.first = i+1; p.second = sum;
		r.pb(p);
	}
	auto f = [] (const auto& lhs, const auto& rhs) {
		if (lhs.second == rhs.second) {
			return lhs.first < rhs.first;
		}
		return lhs.second  < rhs.second;
	};
	sort(begin(r), end(r), f);
	for (auto& a : r) {
		cout << a.first << " " << a.second << '\n';
	}
}

int32_t main() 
{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin); 
//#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//int t; cin >> t;
	//while(t--)
	solve();
}
