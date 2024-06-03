#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
	int n; cin >> n;
	vector<int> v(n), prop(n);
	for (int i = 0; i < n-1; i++) cin >> v[i];
	prop[0] = v[0]+1;
	for (int i = 1; i < n; i++) {
		prop[i] = v[i-1] + ((floor((float)v[i]/prop[i-1])+1)*prop[i-1]);
	}
	for (auto a : prop) cout << a << " ";
	cout << '\n';
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
