/*
  Author: Joel Ostos
  Date: 2024-05-27 
  Problem: https://codeforces.com/contest/1977/problem/A 
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

void solve()
{
  int n; cin >> n;
  vi a(n), b(n+1);
  vpi results;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i <= n; i++) cin >> b[i];
  int res = 0; 

  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]){
      res += abs(a[i] - b[i]);
    }
    results.pb({min(a[i], b[i]),max(a[i], b[i])});
  }
  int target = b[n];
  int mn  = LLONG_MAX, mx = 0;
  for (int i = 0; i < n; i++) {
    if (results[i].ff < mn) {
      mn = results[i].ff;
    } 
    if (results[i].ss < mn) {
      mn = results[i].ss;
    } 
    if (results[i].ss > mx){
      mx = results[i].ss;
    }
    if (results[i].ff > mx){
      mx = results[i].ff;
    }
  }
  for (int i = 0; i < n; i++) {
    if (target >= results[i].ff and target <= results[i].ss) {
      res += 1;
      cout << res << '\n';
      return;
    }
  }
  int res1 = LLONG_MAX, res2 = LLONG_MAX;
  bool pass = 0;
  if (target <= mn) {
    res1 = abs(mn - target);
    pass = 1;
  }
  if (target >= mx) {
    res2 = abs(mx - target);
    pass = 1;
  }
  if (pass) {
    cout << res+min(res1, res2)+1 << '\n';
    return;
  }
  cout << res+1<< '\n';
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
