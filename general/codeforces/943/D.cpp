#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
	int n, k, idx_b, idx_s; cin >> n >> k >> idx_b >> idx_s;
	vector<int> p(n), a(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) cin >> a[i];
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
