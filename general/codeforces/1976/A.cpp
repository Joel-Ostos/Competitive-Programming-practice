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

#define fori(n, jump) for (int i = 0; i < n; i+=jump)
#define fore(beg, n, jump) for (int i = beg; i < n; i+=jump)
#define foreq(beg, n, jump) for (int i = beg; i <= n; i+=jump)
#define fora(container) for (auto it : container)

void solve()
{
  int n; cin >> n;
  string str; cin >> str;

  for (int i = 1; i < n; i++) {
    if (isdigit(str[i]) and !isdigit(str[i-1])) {
      cout << "NO\n";
      return;
    }
  }
  string nums, letters, snums, sletters;
  
  for (int i = 0; i < n; i++) {
    if (isdigit(str[i])) {
      nums.pb(str[i]);
    } else {
      letters.pb(str[i]);
    }
  }
  sletters = letters;
  snums = nums;
  sort(sletters.begin(), sletters.end());
  sort(snums.begin(), snums.end());
  for (int i = 0; i < nums.size(); i++) {
    if (snums[i]!=nums[i]) {
      cout << "NO\n";
      return;
    }
  }
  for (int i = 0; i < letters.size(); i++) {
    if (sletters[i]!=letters[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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
