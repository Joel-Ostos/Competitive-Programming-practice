#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
	int a, b, c, d; cin >> a >> b >> c >> d;
	int a_b = a > b ? a : b;
	int a_l = a < b ? a : b;
	int b_b = c > d ? c : d;
	int b_l = c < d ? c : d;
	if (b_b > a_b and b_l < a_b and b_l > a_l) {
		cout << "YES\n";
		return;
	}
	if (b_b < a_b and b_b > a_l and b_l < a_l) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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
