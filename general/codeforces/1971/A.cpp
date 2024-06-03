#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
	int x,y; cin >> x >> y;
	if (x>y) {
		cout << y << " " << x << '\n';
		return;
	} 
	cout << x << " " << y <<'\n';
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
