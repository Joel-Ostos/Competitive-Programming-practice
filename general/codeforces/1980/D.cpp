/*
  Author: Joel Ostos
  Date: 2024-06-03 
  Problem: https://codeforces.com/contest/1980/problem/D 
*/

#include <bits/stdc++.h>
using namespace std;

#define __FILENAME__ strrchr("/" __FILE__, '/') + 1 

#define int long long
#define pb push_back
#define pii pair<int, int> 
#define vi vector<int> 
#define vb vector<bool> 
#define vpi vector<pair<int, int>> 
#define vvi vector<vector<int>>
#define um unordered_map
#define ff first
#define ss second
#define all(container) container.begin(), container.end()

#define fori(n, jump) for (int i = 0; i < n; i+=jump)
#define fore(beg, n, jump) for (int i = beg; i < n; i+=jump)
#define foreq(beg, n, jump) for (int i = beg; i <= n; i+=jump)
#define fora(container) for (auto it : container)

void solve()
{
	int n; cin >> n;
	vi v(n);
	fori(n, 1) cin >> v[i];
	vi b;
	fore(1, n, 1) {
		b.pb(gcd(v[i], v[i-1]));
	}
	int diff = 0;
	vi idxs;
	fore(1, b.size(), 1) {
		if (b[i-1] > b[i]) {
			diff++;
			idxs.pb(i-1);
			idxs.pb(i-2);
			idxs.pb(i);
			idxs.pb(i+1);
		}
	}
	if (idxs.size() == 0) {
		cout << "YES\n";
		return;
	}
	fori (idxs.size(), 1) {
		int idx_1 = idxs[i];
		bool f = 0;
		vi c;
		vi r1;
		fori (n, 1) {
			if (idx_1 == i) continue;
			c.pb(v[i]);
		}
		fore(1, c.size(), 1) {
			r1.pb(gcd(c[i], c[i-1]));
		}
		fore (1, r1.size(), 1) {
			if (r1[i-1] > r1[i]) {
				f = 1;
				break;
			}
		}
		if (!f) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

int32_t main()
{
#ifndef ONLINE_JUDGE
  string str = "";
  str = __FILENAME__;
  string input = ""; input.pb(str[0]);
  input += "_input.txt";
  string output = ""; output.pb(str[0]);
  output += "_out.txt";
  freopen(input.c_str(), "r", stdin);
  freopen(output.c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while(t--) solve();
}
