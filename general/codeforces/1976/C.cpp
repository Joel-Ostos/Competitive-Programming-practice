/*
  Author: Joel Ostos
  Date: 2024-05-30 
  Problem: https://codeforces.com/contest/1976/problem/C
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
  int n, m; cin >> n >> m;
  vpi can(n+m+1);
  for (int i = 0; i < n+m+1; i++) cin >> can[i].ff;
  for (int i = 0; i < n+m+1; i++) cin >> can[i].ss;
  um<int, pii> devs, testers;
  pii no_tester, no_dev;
  no_tester.ff = no_dev.ff = LLONG_MIN;
  no_tester.ss = no_dev.ss = LLONG_MIN;

  for (int i = 0; i < n+m; i++) {
    if (can[i].ff > can[i].ss and devs.size() < n) {
      devs[i] = can[i];
    } else if (can[i].ff > can[i].ss and devs.size() >= n and testers.size() < m) {
      testers[i] = can[i];
      if (no_tester.ff == LLONG_MIN and no_tester.ss == LLONG_MIN ) {
	no_tester = can[i];
      }
    }
    if (can[i].ff < can[i].ss and testers.size() < m) {
      testers[i] = can[i];
    } else if (can[i].ff < can[i].ss and testers.size() >= m and devs.size() < n) {
      devs[i] = can[i];
      if (no_dev.ff == LLONG_MIN and no_dev.ss == LLONG_MIN ) {
	no_dev = can[i];
      }
    }
  }

  int sum = 0;

  for (int i = 0; i < n+m; i++) {
    if (devs.find(i) != devs.end()) {
      sum += devs[i].ff;
    }
    if (testers.find(i) != testers.end()) {
      sum += testers[i].ss;
    }
  }

  int tmp_sum = sum;

  for (int i = 0; i < n+m+1; i++) {
    if (devs.find(i) != devs.end()) {
      bool f = 0;
      tmp_sum -= devs[i].ff;
      if (no_tester.ff != LLONG_MIN and no_tester.ss != LLONG_MIN ) {
	tmp_sum += no_tester.ff;
	tmp_sum -= no_tester.ss;
      } else  {
	tmp_sum += can[n+m].ff;
	f = 1;
      }
      if (!f) tmp_sum += can[n+m].ss;
    }
    if (testers.find(i) != testers.end()) {
      bool f = 0;
      tmp_sum -= testers[i].ss;
      if (no_dev.ff != LLONG_MIN and no_dev.ss != LLONG_MIN) {
	tmp_sum += no_dev.ss;
	tmp_sum -= no_dev.ff;
      } else {
	f = 1;
	tmp_sum += can[n+m].ss;
      }
      if (!f) tmp_sum += can[n+m].ff;
    }
    cout << tmp_sum << ' ';
    tmp_sum = sum;
  }
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
