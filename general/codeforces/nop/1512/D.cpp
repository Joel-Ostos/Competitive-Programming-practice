/*
  Author: Joel Ostos
  Date: 2024-06-02 
  Problem: https://codeforces.com/contest/1512/problem/D 
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
	vi ans(n), v(n+2);
 
	fori (n+2, 1) cin >> v[i];
 
	sort(all(v));
	int mxv = v[n+1], mnv = v[n], sum_mx = 0, sum_mn = 0;

	fori(n+2, 1) {
		if (i != n+1) sum_mx += v[i];
		if (i != n) sum_mn += v[i];
	}

	fori (n+2, 1) {
		if (sum_mx - v[i] == mxv and i != n+1) {
			for (int j = 0; j < n+2; j++) {
				if (j == i or j == n+1) continue;
				cout << v[j] << " ";
			}
			cout << '\n';
			return;
		}
		if (sum_mn - v[i] == mnv and i != n) {
			for (int j = 0; j < n+2; j++) {
				if (j == i or j == n) continue;
				cout << v[j] << " ";
			}
			cout << '\n';
			return;
		}
	}
	cout << "-1\n";
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
