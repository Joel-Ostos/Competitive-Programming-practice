/*
  Author: Joel Ostos
  Date: 2024-06-01 
  Problem: https://codeforces.com/contest/1512/problem/B 
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

#define fori(n, jump) for (int i = 0; i < n; i+=jump)
#define fore(beg, n, jump) for (int i = beg; i < n; i+=jump)
#define foreq(beg, n, jump) for (int i = beg; i <= n; i+=jump)
#define fora(container) for (auto it : container)

void solve()
{
  int n; cin >> n;
  vector<string> v(n);
  fori(n, 1) cin >> v[i];
  pair<int, int> first_c = {-1, -1};
  pair<int, int> second_c = {-1, -1};
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (v[i][j] == '*' and first_c.ff == -1) {
	first_c.ff = i;
	first_c.ss = j;
	continue;
      }
      if (v[i][j] == '*' and second_c.ff == -1 and first_c.ff != -1) {
	second_c.ff = i;
	second_c.ss = j;
      }
    }
  }
  if (first_c.ff != second_c.ff and first_c.ss != second_c.ss) {
    v[second_c.ff][first_c.ss] = '*';
    v[first_c.ff][second_c.ss] = '*';
    fora (v) {
      cout << it << '\n';
    }
    return;
  }
  if (first_c.ff != second_c.ff and first_c.ss == second_c.ss) {
    if (first_c.ss == n-1 and second_c.ss == n-1) {
      v[first_c.ff][n-2] = '*';
      v[second_c.ff][n-2] = '*';
      fora (v) {
        cout << it << '\n';
      }
      return;
    }
    v[first_c.ff][first_c.ss+1] = '*';
    v[second_c.ff][second_c.ss+1] = '*';
    fora (v) {
      cout << it << '\n';
    }
    return;
  }
  if (first_c.ff == second_c.ff and first_c.ss != second_c.ss) {
    if (first_c.ff == n-1 and second_c.ff == n-1) {
      v[first_c.ff-1][first_c.ss] = '*';
      v[second_c.ff-1][second_c.ss] = '*';
      fora (v) {
        cout << it << '\n';
      }
      return;
    }
    v[first_c.ff+1][first_c.ss] = '*';
    v[second_c.ff+1][second_c.ss] = '*';
    fora (v) {
      cout << it << '\n';
    }
    return;
  }
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
  //freopen(output.c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while(t--) solve();
}
