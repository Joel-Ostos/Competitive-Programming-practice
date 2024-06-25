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
  int n, m; cin >> n >> m;
  vector<string> v(n);
  for (int i = 0; i < n; i++) { cin >> v[i]; }
  pair<int, int> first = {-1, -1};
  pair<int, int> last = {-1, -1};
  bool f = 0;
  for (int i = 0; i < n; i++) {
    pair<int, int> coor;
    int nums = 0;
    for (int j = 0; j < m; j++) {
    	if (v[i][j] == '#') {
		coor.ff = i+1;
		coor.ss = j+1;
		nums++;
	}
    }
    if (first.ff == -1 and nums == 1 and !f) {
	    first = coor;
	    last = coor;
	    f = 1;
    } else if (nums == 1 and f) {
	    last = coor;
    }
  }
  if (first.ff == last.ff and first.ss == last.ss) {
  	cout << first.ff << " " << first.ss << '\n';
	return;
  }
  int res = first.ff + ((last.ff - first.ff)/ 2);
  cout << res << " " << first.ss << '\n';
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
