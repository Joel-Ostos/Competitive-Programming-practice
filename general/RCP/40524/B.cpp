#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
	int n, a, k; cin >> n >> a >> k;
	int actual = 0;
	for (int i = 1; actual < n; i++) {
		actual = a*i;
		int actual_b = k;
		for (int j = 1; actual_b < n; j++) {
			actual_b = k*j;
			if (actual_b+actual == n) {
				cout << "1\n";
				return;
			}
		}
	}
	cout << "0\n";
}

int32_t main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}
