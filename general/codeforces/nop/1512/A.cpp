/*
  Author: Joel Ostos
  Date: 2024-06-01 
  Problem: https://codeforces.com/contest/1512/problem/A 
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

typedef struct triple {
  int ff;
  int ss;
  int tt;
} tripla;

void solve()
{
  int n; cin >> n;
  vi v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vpi ans;
  ans.pb({v[0], 0});
  for (int i = 1; i < n; i++) {
    if (v[i] != ans[0].ff) {
      ans.pb({v[i], i});
      break;
    }
  }
  int oc = 0;
  for (int i = 1; i < n; i++) {
    if (ans[0].ff == v[i]) {
      oc++;
    }
  }

  if (oc>0) {
    cout << ans[1].ss+1 << '\n';
    return;
  }

  cout << ans[0].ss+1 << '\n';
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
